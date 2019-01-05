/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "driveTrain.h"
#include "cubeManipulator.h"
#include "TrapezoidalMove.h"


class Autonomous {
 private:
  cubeManipulator &cubeManip;
  driveTrain &drive;
  TrapezoidalMove tuve;
  Timer m_timer;

  int m_autoState;
  int m_moveState;
 public:
  Autonomous(cubeManipulator &cubeManip, driveTrain &drive);
  void AutoPeriodic();
};
