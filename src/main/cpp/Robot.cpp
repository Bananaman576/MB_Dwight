/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>
#include <Joystick.h>
#include <ctre/Phoenix.h>
#include "dwight.h"
#include "driveTrain.h"
#include "cubeManipulator.h"
#include "Autonomous.h"


class Robot : public frc::TimedRobot {
  Dwight dwight;
  cubeManipulator cubeManip;
  driveTrain drive;
  Autonomous auton;
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
 public:
  Robot() : drive(dwight), cubeManip(dwight), auton(cubeManip, drive) {
 
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void AutonomousInit() {

}

void AutonomousPeriodic() {
  auton.AutoPeriodic();
}

void TeleopInit() {}

void TeleopPeriodic() {
  cubeManip.CubeTeleopPeriodic();
  drive.driveTeleopPeriodic();
}

void TestPeriodic() {}
};
#ifndef RUNNING_FRC_TESTS
START_ROBOT_CLASS(Robot)
#endif
