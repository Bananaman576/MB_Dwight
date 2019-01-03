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
}
void driveTrain::DriveAround(double leftSpeed, double rightSpeed) {
  dwight.leftDrive1->Set(ControlMode::PercentOutput, leftSpeed);
  dwight.rightDrive1->Set(ControlMode::PercentOutput, rightSpeed);
}


