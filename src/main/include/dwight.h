#pragma once
#include <WPILib.h>
#include <ctre/Phoenix.h>

class Dwight {
    public:
    TalonSRX* rightDrive1 = new TalonSRX(1);
    TalonSRX* rightDrive2 = new TalonSRX(2);
    VictorSPX* rightDrive3 = new VictorSPX(3);
    TalonSRX* leftDrive1 = new TalonSRX(4);
    TalonSRX* leftDrive2 = new TalonSRX(5);
    VictorSPX* leftDrive3 = new VictorSPX(6);
    VictorSPX* leftArm = new VictorSPX(7);
    VictorSPX* rightArm = new VictorSPX(8);
    TalonSRX* goodAxle = new TalonSRX(11);
    TalonSRX* lessGoodAxle = new TalonSRX(12);
    frc::Solenoid* cubeClamp = new Solenoid(7);
    frc::Joystick* m_stick = new frc::Joystick(0);

    
    
};