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

//const int ROLLERS_MOTOR = 5;
//const int ROLLERS_MOTOR_2 = 9;

const int ROLLERS_MOTOR_LIFT_RIGHT = 8;
const int ROLLERS_MOTOR_LIFT_LEFT = 4;

const int ROLLERS_MOTOR_LEFT = 5;
const int ROLLERS_MOTOR_RIGHT = 9;
const int ROLLERS_MOTOR_LEFT_PDP = 4;
const int ROLLERS_MOTOR_RIGHT_PDP = 8;
const int ROLLER_DOWN = 3;
////////////////////////////////////////////////////////////
const int LEFT_MOTOR_MASTER = 1; // the values assigned are temporary until talon values are identified
const int LEFT_MOTOR_FOLLOWER = 2;
const int LEFT_MOTOR_FOLLOWER_2 = 3;
////////////////////////////////////////////////////////////
const int RIGHT_MOTOR_MASTER = 12;
const int RIGHT_MOTOR_FOLLOWER = 13;
const int RIGHT_MOTOR_FOLLOWER_2 = 14;
//const int RIGHT_MOTOR_MASTER = 13; // temp values for practice robot
//const int RIGHT_MOTOR_FOLLOWER = 14;
//const int RIGHT_MOTOR_FOLLOWER_2 = 15;

////////////////////////////////////////////////////////////
const int SOL_SHIFTER_1 = 2;
const int SOL_SHIFTER_2 = 3;
const int COMPRESSOR = 0;
////////////////////////////////////////////////////////////
const float RAMP = 30;
////////////////////////////////////////////////////////////

const int Talon_Lift_Setter = 70;

const int TALON_LIFT = 80;
const int TALON_LIFT_2 = 90;

////////////////////////////////////////////////////////////

const float DPAD = .5;

////////////////////////////////////////////////////////////

const int TALON_WINCH_1 = 3;
const int TALON_WINCH_2 = 9;
const int WINCH_SPEED = 255;

////////////////////////////////////////////////////////////

const int SOL_CLIMBER_1 = 0;
const int SOL_CLIMBER_2 = 1;

#endif
