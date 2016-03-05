#include "Climber.h"
#include "Commands/CommandWinch.h"
#include "../RobotMap.h"

Climber::Climber() :
		Subsystem("Climber")
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
	SetDefaultCommand(new CommandWinch());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Climber::Winch(bool _clockwise){
	bool clockwise = _clockwise;
	if (clockwise){
		WinchTalon_1->Set(10);
		WinchTalon_2->Set(10);
	}
	else {
		WinchTalon_1->Set(-10);
		WinchTalon_2->Set(-10);
	}
}
void Climber::StopWinch(){
	WinchTalon_1->Set(0);
	WinchTalon_2->Set(0);
}
