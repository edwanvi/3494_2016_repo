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

const int ROLLERS_MOTOR = 666;


const int LEFT_MOTOR_MASTER = 1; // real val 1
const int LEFT_MOTOR_FOLLOWER = 2;
const int LEFT_MOTOR_FOLLOWER_2 = 3;
////////////////////////////////////////////////////////////
const int RIGHT_MOTOR_MASTER = 12; // real val 12
const int RIGHT_MOTOR_FOLLOWER = 13;
const int RIGHT_MOTOR_FOLLOWER_2 = 14;
////////////////////////////////////////////////////////////
const int SOL_SHIFTER_1 = 0;
const int SOL_SHIFTER_2 = 1;
const int COMPRESSOR = 0;
////////////////////////////////////////////////////////////
const float RAMP = 24;
////////////////////////////////////////////////////////////
const int Talon_Lift_Setter = 70;
const int Talon_Lift = 80;
const int Talon_LIft_2 = 90;
////////////////////////////////////////////////////////////
const float DPAD = .5;

#endif
