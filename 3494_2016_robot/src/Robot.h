/*
 * Robot.h
 *
 *  Created on: Feb 20, 2016
 *      Author: science
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include "WPILib.h"
#include "Commands/Drive/Drive.h"
#include "Subsystems/DriveTrain.h"

class Robot: public IterativeRobot {
public:
	Command *autonomousCommand;
	Command *Auto_Score;
	LiveWindow *lw;
	DriveTrain* drivetrain;
	AHRS *ahrs;

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void teleopPeriodic();
	void DisabledPeriodic();
	void TestPeriodic();
};




#endif /* SRC_ROBOT_H_ */
