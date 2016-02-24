#include "Robot_Lift.h"
#include "../RobotMap.h"
#include "../Commands/Lifting.h"

Robot_Lift::Robot_Lift() :
		Subsystem("Lift")
{
////////////////////////////////////////////////////////////

	TalonLift_Setter = new CANTalon(Talon_Lift_Setter);
	TalonLift_Setter->EnableControl();

	TalonLift_Setter->SetSafetyEnabled(false);
	TalonLift_Setter->SetExpiration(0.100);
	TalonLift_Setter->Set(0); //
////////////////////////////////////////////////////////////
	/*Talon_Lift = new Talon(Talon_Lift);

	Talon_Lift->SetSafetyEnabled(false);
	Talon_Lift->SetExpiration(0.100);
	Talon_Lift->Set(0);
////////////////////////////////////////////////////////////
	Talon_Lift_2 = new Talon(Talon_Lift_2);

	Talon_Lift_2->SetSafetyEnabled(false);
	Talon_Lift_2->SetExpiration(0.100);
	Talon_Lift_2->Set(0); */
////////////////////////////////////////////////////////////

}

void Robot_Lift::InitDefaultCommand()
{

	//SetDefaultCommand(new Lifting());

}

void Robot_Lift::Lift(int mode)
{



}
// Put methods for controlling this subsystem
// here. Call these from Commands.
