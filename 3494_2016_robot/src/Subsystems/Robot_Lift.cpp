#include "Robot_Lift.h"
#include "../RobotMap.h"
#include "../Commands/Lifting.h"

Robot_Lift::Robot_Lift() :
		Subsystem("Robot_Lift")
{
////////////////////////////////////////////////////////////

	TalonLift_Setter = new CANTalon(Talon_Lift_Setter);
	TalonLift_Setter->EnableControl();

	TalonLift_Setter->SetSafetyEnabled(false);
	TalonLift_Setter->SetExpiration(0.100);
	TalonLift_Setter->Set(0);

////////////////////////////////////////////////////////////

	TalonLift = new CANTalon(TALON_LIFT);
	TalonLift->EnableControl();
	TalonLift->SetSafetyEnabled(false);
	TalonLift->SetExpiration(0.100);
	TalonLift->Set(0);

////////////////////////////////////////////////////////////
	TalonLift_2 = new CANTalon(TALON_LIFT_2);
	TalonLift_2->EnableControl();
	TalonLift_2->SetSafetyEnabled(false);
	TalonLift_2->SetExpiration(0.100);
	TalonLift_2->Set(0);

}

void Robot_Lift::InitDefaultCommand()
{
	//SetDefaultCommand(new Lifting());
}

void Robot_Lift::Lift(int mode)
{
	//if () add conditional when we have the limit switch system ready

	TalonLift->Set(mode);
	TalonLift_2->Set(-mode);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
