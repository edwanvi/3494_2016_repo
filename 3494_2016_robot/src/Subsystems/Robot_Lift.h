#ifndef Robot_Lift_H
#define Robot_Lift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Robot_Lift: public Subsystem
{
private:
	CANTalon* TalonLift;	// initializing lift objects
	CANTalon* TalonLift_2;


public:
	Robot_Lift();
	void InitDefaultCommand();
	void Lift(float magnitude);
};

#endif
