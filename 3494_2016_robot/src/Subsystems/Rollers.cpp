#include "Subsystems/Rollers.h"
#include "../RobotMap.h"

Rollers::Rollers() :
		Subsystem("Rollers")
{
	//create a talon object to control the rollers
	talon_rollers = new CANTalon(666);
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
void Rollers::Roll(bool forward){
	if (forward == true){
		talon_rollers->Set(1);
	}
	else {
		talon_rollers->Set(-1);
	}
}
