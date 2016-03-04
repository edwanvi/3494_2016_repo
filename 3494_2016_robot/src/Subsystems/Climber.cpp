#include "Climber.h"
#include "../RobotMap.h"

Climber::Climber() :
		Subsystem("ExampleSubsystem")
{
	WinchTalon_1 = new Talon(TALON_WINCH_1);
	WinchTalon_1->SetSafetyEnabled(false);

	WinchTalon_2 = new Talon(TALON_WINCH_2);
	WinchTalon_2->SetSafetyEnabled(false);
}

void Climber::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Climber::Winch(bool _clockwise){
	bool clockwise = _clockwise;
	if (clockwise){
		WinchTalon_1->Set(DPAD);
		WinchTalon_2->Set(-DPAD);
	}
	else {
		WinchTalon_1->Set(-DPAD);
		WinchTalon_2->Set(DPAD);
	}
}
