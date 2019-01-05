/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Autonomous.h"

Autonomous::Autonomous(cubeManipulator &cubeManip, driveTrain &drive) : cubeManip(cubeManip) , drive(drive) {
    drive.autoPrep();
    m_autoState = 0;
    m_moveState = 0;
}

void Autonomous::AutoPeriodic(){
    double distance;
    double t = m_timer.Get();
    printf("AutoState: %i MoveState: %i",m_autoState,m_moveState);
        switch(m_autoState) {
        case 0:
        //init
        m_autoState++;
        break;
        case 1:
        //drive to switch
        switch(m_moveState){
            case 0:
            //init
            tuve.SetAll(10,10,10,50);
            m_timer.Reset();
            m_timer.Start();
            m_moveState++;
            break;
            case 1:
             distance = tuve.Position(t);
             printf("Distance: %f",distance);
            drive.driveDistance(distance*1.3333,distance*.75);
            if(t>tuve.GetTotalTime()){
                m_moveState++;
            }
            break;
            case 2:
            m_timer.Stop();
            m_autoState++;
            m_moveState = 0;
            drive.moveReset();
            break;



        }

        break;
        case 2:
        switch(m_moveState){
            case 0:
            //init
            tuve.SetAll(10,10,10,50);
            m_timer.Reset();
            m_timer.Start();
            m_moveState++;
            break;
            case 1:
             distance = tuve.Position(t);
             printf("Distance: %f",distance);
            drive.driveDistance(distance*.75,distance*1.333);
            if(t>tuve.GetTotalTime()){
                m_moveState++;
            }
            break;
            case 2:
            m_timer.Stop();
            m_autoState++;
            m_moveState = 0;
            drive.moveReset();
            break;



        }
        break;
        case 3:
        switch(m_moveState){
            case 0:
            //init
            tuve.SetAll(10,10,10,46);
            m_timer.Reset();
            m_timer.Start();
            m_moveState++;
            break;
            case 1:
             distance = tuve.Position(t);
             printf("Distance: %f",distance);
            drive.driveDistance(distance,distance);
            if(t>tuve.GetTotalTime()){
                m_moveState++;
            }
            break;
            case 2:
            m_timer.Stop();
            m_autoState++;
            m_moveState = 0;
            drive.moveReset();
            break;
        }
        break;
        case 4:
        if(cubeManip.FlipADip(45)){
            cubeManip.intakeCube();
        }

    }
}
