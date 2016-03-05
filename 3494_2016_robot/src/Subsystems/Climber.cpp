#include "Climber.h"
#include "Commands/CommandWinch.h"
#include "../RobotMap.h"

Climber::Climber() :
		Subsystem("Climber")
{
/////////////////////////////////////////////////////////////////

	WinchTalon_1 = new Talon(TALON_WINCH_1);	// will switch to srx during competition
	WinchTalon_1->SetSafetyEnabled(false);

	WinchTalon_2 = new Talon(TALON_WINCH_2);
	WinchTalon_2->SetSafetyEnabled(false);
/////////////////////////////////////////////////////////////////
	pdp = new PowerDistributionPanel();
	SmartDashboard::init();
/////////////////////////////////////////////////////////////////
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
	bool clockwise = _clockwise; // if true then the dpad value is 0
	if (clockwise){
		WinchTalon_1->Set(110); // values are the same because of mechanical
		WinchTalon_2->Set(110);
	}
	else {						// if 180 then the value sent is false
		WinchTalon_1->Set(-255);
		WinchTalon_2->Set(-255);
	}
	int current_1 = pdp->GetCurrent(8); // these will be srx's
	int current_2 = pdp->GetCurrent(9); // so wait till later to add to robot map for competition
	SmartDashboard::PutNumber("Lift Current 1", current_1);
	SmartDashboard::PutNumber("Lift Current 2", current_2);
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
}
void Climber::StopWinch(){ // wench stop when neither is present
	WinchTalon_1->Set(0);
	WinchTalon_2->Set(0);
}

void Climber::Setter()
{


}
