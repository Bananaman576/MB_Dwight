#pragma once
#include <WPILib.h>
#include <ctre/Phoenix.h>

class Dwight {
    public:
    TalonSRX* rightDrive1 = new TalonSRX(1);
    TalonSRX* rightDrive2 = new TalonSRX(2);
    TalonSRX* rightDrive3 = new TalonSRX(3);
    TalonSRX* leftDrive1 = new TalonSRX(4);
    TalonSRX* leftDrive2 = new TalonSRX(5);
    TalonSRX* leftDrive3 = new TalonSRX(6);
    TalonSRX* leftArm = new TalonSRX(7);
    TalonSRX* rightArm = new TalonSRX(8);
    TalonSRX* goodAxle = new TalonSRX(11);
    TalonSRX* lessGoodAxle = new TalonSRX(12);
    frc::Solenoid* cubeClamp = new Solenoid(3);
    frc::Joystick* m_stick = new frc::Joystick(0);
    
    
};