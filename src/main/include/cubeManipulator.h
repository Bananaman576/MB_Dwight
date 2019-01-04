/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "dwight.h"
#include <ctre/Phoenix.h>
#include "TrapezoidalMove.h"
class cubeManipulator{
 private:
  Timer m_timer;
  int m_state;
  double m_currentAngle;
  void SetAngle(double);
  void SpinToWin(double, double);
  void makeTheLiftNotSuck(bool);
  Dwight &dwight;
  TrapezoidalMove tuve;

 public:
  bool FlipADip(double);
  void intakeCube();
  void outputCube();
  void spinCube();
  void Stop();
  cubeManipulator(Dwight &dwight);
  void CubeTeleopPeriodic();
  void Reset();
};
