/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "cubeManipulator.h"

cubeManipulator::cubeManipulator(Dwight &dwight, TrapezoidalMove &tuve) : dwight(dwight) , tuve(tuve) {
  dwight.lessGoodAxle->Follow(*dwight.goodAxle);
  dwight.goodAxle->SetSensorPhase(true);
  dwight.goodAxle->SetInverted(true);
  dwight.lessGoodAxle->SetInverted(false);
  dwight.leftArm->SetInverted(true);
  dwight.rightArm->SetInverted(false);
  m_state=0;
  m_currentAngle=0;

}

void cubeManipulator::SetAngle(double flipAngle) {
  double ticks = flipAngle * 68.267;
  dwight.goodAxle->Set(ControlMode::Position, ticks);
  m_currentAngle=flipAngle;
}

bool cubeManipulator::FlipADip(double flipAngle){
  double angleChange;
  double setPoint;
  double startingAngle;
  double t = m_timer.Get();
  switch(m_state){
    case 0:
    startingAngle = m_currentAngle;
    angleChange = flipAngle - startingAngle;
    tuve.SetAll(200,300/2,300,fabs(angleChange));
    m_timer.Reset();
    m_timer.Start();
    m_state++;
    break;
    case 1:
    setPoint = tuve.Position(t);
    if(angleChange<0){
      setPoint *= -1;
    }
    setPoint+=startingAngle;
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

}