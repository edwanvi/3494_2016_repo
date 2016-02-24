#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

const int ROLLERS_MOTOR = 5;
const int ROLLERS_MOTOR_2 = 9;

const int LEFT_MOTOR_MASTER = 40; // the values assigned are temporary until talon values are identified
const int LEFT_MOTOR_FOLLOWER = 50;
const int LEFT_MOTOR_FOLLOWER_2 = 60;
////////////////////////////////////////////////////////////
const int RIGHT_MOTOR_MASTER = 10; // temp values for right motors as viewed from the front of robot
const int RIGHT_MOTOR_FOLLOWER = 20;
const int RIGHT_MOTOR_FOLLOWER_2 = 30;
////////////////////////////////////////////////////////////
const int SOL_SHIFTER_1 = 0;
const int SOL_SHIFTER_2 = 1;
const int COMPRESSOR = 0;
////////////////////////////////////////////////////////////
const float RAMP = 6.0;
////////////////////////////////////////////////////////////
<<<<<<< HEAD
const int Talon_Lift = 70;
const int Talon_Lift_2 = 80;
=======
const int Talon_Lift_Setter = 70;
const int TALON_LIFT = 80;
const int TALON_LIFT_2 = 90;
<<<<<<< HEAD
>>>>>>> branch 'master' of https://github.com/tkdberger/3494_2016_repo.git
=======
>>>>>>> refs/remotes/origin/master
////////////////////////////////////////////////////////////


#endif
