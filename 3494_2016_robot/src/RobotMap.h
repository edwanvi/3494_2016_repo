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
const int ROLLERS_MOTORS = 666;

const int LEFT_MOTOR_MASTER = 1; // the values assigned are temporary until talon values are identified
const int LEFT_MOTOR_FOLLOWER = 2;
const int LEFT_MOTOR_FOLLOWER_2 = 3;
////////////////////////////////////////////////////////////
const int RIGHT_MOTOR_MASTER = 4; // temp values for right motors as viewed from the front of robot
const int RIGHT_MOTOR_FOLLOWER = 5;
const int RIGHT_MOTOR_FOLLOWER_2 = 6;
////////////////////////////////////////////////////////////


#endif
