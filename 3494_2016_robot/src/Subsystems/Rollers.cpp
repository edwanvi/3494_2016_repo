#include "Rollers.h"
#include "../RobotMap.h"

Rollers::Rollers() :
		Subsystem("Rollers")
{
	//create a talon object to control the rollers
	talon_rollers = new CANTalon(Rollers);
	talon_rollers -> EnableControl();
	talon_rollers -> SetSafetyEnabled(false);
}

void Rollers::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
