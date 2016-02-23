#include "Robot_Lift.h"
#include "../RobotMap.h"
#include "../Commands/Lifting.h"

Robot_Lift::Robot_Lift() :
		Subsystem("Lift")
{
////////////////////////////////////////////////////////////

	TalonLift = new CANTalon(Talon_Lift);
	TalonLift->EnableControl();

	TalonLift->SetSafetyEnabled(false);
	TalonLift->SetExpiration(0.100);
	TalonLift->Set(0); //
////////////////////////////////////////////////////////////

	TalonLift_2 = new CANTalon(Talon_Lift_2);
	TalonLift_2->EnableControl();

	TalonLift_2->SetSafetyEnabled(false);
	TalonLift_2->SetExpiration(0.100);
	TalonLift_2->Set(0);
////////////////////////////////////////////////////////////

}

void Robot_Lift::InitDefaultCommand()
{

	SetDefaultCommand(new Lifting());

}

void Robot_Lift::Lift(float magnitude)
{
	//if () add conditional when we have the limit switch system ready

	TalonLift->Set(magnitude);
	TalonLift_2->Set(-magnitude);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.