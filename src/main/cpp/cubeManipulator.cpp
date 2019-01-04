/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "cubeManipulator.h"

cubeManipulator::cubeManipulator(Dwight &dwight) : dwight(dwight) {
  dwight.lessGoodAxle->Follow(*dwight.goodAxle);
  dwight.goodAxle->SetSensorPhase(true);
  dwight.goodAxle->SetInverted(true);
  dwight.lessGoodAxle->SetInverted(false);
  dwight.leftArm->SetInverted(true);
  dwight.rightArm->SetInverted(false);
  Reset();
  m_state=0;
  m_currentAngle=0;

}
void cubeManipulator::Reset(){
  dwight.leftArm->SetSelectedSensorPosition(0,0,0);
  dwight.rightArm->SetSelectedSensorPosition(0,0,0);
  dwight.goodAxle->SetSelectedSensorPosition(0,0,0);
  dwight.lessGoodAxle->SetSelectedSensorPosition(0,0,0);
}
void cubeManipulator::SetAngle(double flipAngle) {
  double ticks = flipAngle * 68.267;
  dwight.goodAxle->Set(ControlMode::Position, ticks);
  m_currentAngle=flipAngle;
  printf("Current Angle: %f \n",m_currentAngle);
}

bool cubeManipulator::FlipADip(double flipAngle){
  static double angleChange;
  double setPoint;
  static double startingAngle;
  double t = m_timer.Get();
  switch(m_state){
    case 0:
    startingAngle = m_currentAngle;
    angleChange = flipAngle - startingAngle;
    tuve.SetAll(200,300/2,300,fabs(angleChange));
    m_timer.Reset();
    m_timer.Start();
    m_state++;
    printf("StartingAngle: %f TargetAngle: %f AngleChange: %f \n", startingAngle, flipAngle, angleChange);
    break;
    case 1:
    setPoint = tuve.Position(t);
    if(angleChange<0){
      setPoint *= -1;
    }
    setPoint+=startingAngle;
    printf("SetPoint: %f Current Angle: %f \n",setPoint,m_currentAngle);
    SetAngle(setPoint);
    if(t>tuve.GetTotalTime()){
      m_timer.Stop();
      m_state++;
    }
    break;
    case 2:
    return true;
    break;
  }
  return false;
}

void cubeManipulator::SpinToWin(double leftSpeed, double rightSpeed) {
  dwight.leftArm->Set(ControlMode::PercentOutput, leftSpeed);
  dwight.rightArm->Set(ControlMode::PercentOutput, rightSpeed);
}

void cubeManipulator::intakeCube() {
  SpinToWin(-1,-1);
}

void cubeManipulator::outputCube() {
  SpinToWin(1,1);
}

void cubeManipulator::spinCube() {
  SpinToWin(1,-1);
}

void cubeManipulator::Stop() {
  SpinToWin(0,0);
}

void cubeManipulator::makeTheLiftNotSuck(bool clasping) {
  dwight.cubeClamp->Set(!clasping);
}

void cubeManipulator::CubeTeleopPeriodic() {
  //intake is button 7
  //output is button 8
  //spinny is 4
  //open wide is two times five divided by five
  //tada
  if(dwight.m_stick->GetRawButton(7)){
    intakeCube();
  } else if(dwight.m_stick->GetRawButton(8)){
    outputCube();
  } else if(dwight.m_stick->GetRawButton(4)){
    spinCube();
  } else {
    Stop();
  }
  

  if(dwight.m_stick->GetRawButton(2)){
     makeTheLiftNotSuck(false);
  } else {
    makeTheLiftNotSuck(true);
  }

  /*
    top D-Pad is 0
    left corner is 315
    left is 270
    right corner is 45
    right is 90
  */

 if(dwight.m_stick->GetPOV()==0){
  if(FlipADip(0)){
     m_state=2;
   }
 } else if(dwight.m_stick->GetPOV()==45){
   if(FlipADip(45)){
     m_state=2;
   }
 } else if(dwight.m_stick->GetPOV()==90){
   if(FlipADip(90)){
     m_state=2;
   }
 } else if(dwight.m_stick->GetPOV()==315){
   if(FlipADip(-45)){
     m_state=2;
   }
 } else if(dwight.m_stick->GetPOV()==270){
   if(FlipADip(-90)){
     m_state=2;
   }
 } else{
   SetAngle(m_currentAngle);
   m_state=0;
 }
}