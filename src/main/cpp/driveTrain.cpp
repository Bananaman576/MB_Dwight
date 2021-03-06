/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "driveTrain.h"

driveTrain::driveTrain(Dwight &dwight) : dwight(dwight) {
  dwight.leftDrive2->Follow(*dwight.leftDrive1);
  dwight.leftDrive3->Follow(*dwight.leftDrive1);
  dwight.rightDrive2->Follow(*dwight.rightDrive1);
  dwight.rightDrive3->Follow(*dwight.rightDrive1);
  dwight.rightDrive1->SetSensorPhase(true);
  dwight.rightDrive1->SetInverted(true);
  dwight.rightDrive2->SetInverted(true);
  dwight.rightDrive3->SetInverted(true);
  dwight.leftDrive1->SetSensorPhase(true);
  dwight.leftDrive1->SetInverted(false);
  dwight.leftDrive2->SetInverted(false);
  dwight.leftDrive3->SetInverted(false);
  m_reverse=false;
}
void driveTrain::DriveAround(double leftSpeed, double rightSpeed) {
  dwight.leftDrive1->Set(ControlMode::PercentOutput, leftSpeed);
  dwight.rightDrive1->Set(ControlMode::PercentOutput, rightSpeed);
}

void driveTrain::driveDistance(double lval, double rval) {
  lval*=217.299;
  rval*=217.299;
  dwight.leftDrive1->Set(ControlMode::Position, lval);
  dwight.rightDrive1->Set(ControlMode::Position, rval);
}

void driveTrain::moveReset(){
  dwight.leftDrive1->SetSelectedSensorPosition(0,0,0);
  dwight.rightDrive1->SetSelectedSensorPosition(0,0,0);
  dwight.leftDrive1->Set(ControlMode::Position, 0);
  dwight.rightDrive1->Set(ControlMode::Position, 0);
}

void driveTrain::autoPrep(){
  moveReset();
  SetPID(dwight.leftDrive1,1,0,0);
  SetPID(dwight.rightDrive1,1,0,0);
}

void driveTrain::SetPID(TalonSRX *motor, double p, double i, double d){
  motor->Config_kP(0,p,0);
  motor->Config_kI(0,i,0);
  motor->Config_kD(0,d,0);
}

void driveTrain::driveTeleopPeriodic(){
double rightSpeed = .5*dwight.m_stick->GetRawAxis(3);
double leftSpeed = .5*dwight.m_stick->GetRawAxis(1);
if(dwight.m_stick->GetRawButtonPressed(3)){
  m_reverse=!m_reverse;
}
if(dwight.m_stick->GetRawButton(5)){
  leftSpeed*=.5;
  rightSpeed*=.5;
}
if(dwight.m_stick->GetRawButton(6)){
  leftSpeed*=2;
  rightSpeed*=2;
}
if(m_reverse){
  leftSpeed  *=-1;
  rightSpeed *=-1;
}
DriveAround(leftSpeed,rightSpeed);
//you're a number
//left motors are 1
//right motors are 3
//maximum overdrive is 6
//slowboat is 5

}





