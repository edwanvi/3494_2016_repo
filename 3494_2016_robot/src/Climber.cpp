#include "Climber.h"
#include "../Commands/climb/CommandWinch.h"
#include "../RobotMap.h"

Climber::Climber() :
		Subsystem("Climber")
{
/////////////////////////////////////////////////////////////////

	WenchTalon_1 = new Talon(TALON_WINCH_1);	// will switch to srx during competition
	WenchTalon_1->SetSafetyEnabled(false);

	WenchTalon_2 = new Talon(TALON_WINCH_2);
	WenchTalon_2->SetSafetyEnabled(false);
/////////////////////////////////////////////////////////////////
	pdp = new PowerDistributionPanel();
	SmartDashboard::init();
	solenoid_climber_arm = new DoubleSolenoid(SOL_CLIMBER_1, SOL_CLIMBER_2);
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
		WenchTalon_1->Set(110); // values are the same because of mechanical
		WenchTalon_2->Set(110);
	}
	else {						// if 180 then the value sent is false
		WenchTalon_1->Set(-255);
		WenchTalon_2->Set(-255);
	}
	int current_1 = pdp->GetCurrent(8); // these will be srx's
	int current_2 = pdp->GetCurrent(9); // so wait till later to add to robot map for competition
	SmartDashboard::PutNumber("Lift Current 1", current_1);
	SmartDashboard::PutNumber("Lift Current 2", current_2);
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
}
void Climber::StopWinch(){ // wench stop when neither is present
	WenchTalon_1->Set(0);
	WenchTalon_2->Set(0);
}

void Climber::Setter(bool forward)
{
	if (forward){
		solenoid_climber_arm->Set(solenoid_climber_arm->kForward);
	}
	else if (forward == false) {
		solenoid_climber_arm->Set(solenoid_climber_arm->kReverse);
	}
}
