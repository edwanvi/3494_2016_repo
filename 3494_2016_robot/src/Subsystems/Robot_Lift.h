#ifndef Robot_Lift_H
#define Robot_Lift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Robot_Lift: public Subsystem
{
private:
	CANTalon* TalonLift_Setter;	// initializing lift objects
	Talon* Talon_Lift;
	Talon* Talon_Lift_2;


public:
	Robot_Lift();
	void InitDefaultCommand();
	void Lift(int mode);
};

#endif
