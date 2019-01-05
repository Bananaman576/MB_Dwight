/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "dwight.h"
#include <ctre/Phoenix.h>
class driveTrain {
 private:
  void DriveAround(double,double);
  void SetPID(TalonSRX *motor, double, double, double);
  bool m_reverse;
   Dwight &dwight;
 public:
  void driveTeleopPeriodic();
  void driveDistance(double, double);
  void moveReset();
  void driveAutoPeriodic();
  void autoPrep();
  driveTrain(Dwight &dwight);
 
};
