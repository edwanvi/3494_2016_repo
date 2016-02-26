#include "Subsystems/Rollers.h"
#include "../src/Commands/RunRollers.h"
#include "../RobotMap.h"

Rollers::Rollers() :
		Subsystem("Rollers")
{
	//create a talon object to control the rollers
	talon_rollers = new CANTalon(ROLLERS_MOTOR);
	talon_rollers -> EnableControl();
	talon_rollers -> SetSafetyEnabled(false);

	talon_rollers_2 = new CANTalon(ROLLERS_MOTOR_2);
	talon_rollers_2 -> EnableControl();
	talon_rollers_2 -> SetSafetyEnabled(false);
}

void Rollers::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new RunRollers());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Rollers::Roll(bool forward){
	if (forward == true){
		talon_rollers->Set(.75);
		talon_rollers_2->Set(-.75);
	}
	else {
		talon_rollers->Set(-.75);
		talon_rollers_2->Set(.75);
	}
}
