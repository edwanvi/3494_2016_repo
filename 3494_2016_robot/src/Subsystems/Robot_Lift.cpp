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
<<<<<<< HEAD
=======
	Talon_Lift = new Talon(TALON_LIFT);
>>>>>>> branch 'master' of https://github.com/tkdberger/3494_2016_repo.git

<<<<<<< HEAD
	TalonLift_2 = new CANTalon(Talon_Lift_2);
	TalonLift_2->EnableControl();
=======
	Talon_Lift->SetSafetyEnabled(false);
	Talon_Lift->SetExpiration(0.100);
	Talon_Lift->Set(0);
////////////////////////////////////////////////////////////
	Talon_Lift_2 = new Talon(TALON_LIFT_2);
>>>>>>> branch 'master' of https://github.com/tkdberger/3494_2016_repo.git

<<<<<<< HEAD
	TalonLift_2->SetSafetyEnabled(false);
	TalonLift_2->SetExpiration(0.100);
	TalonLift_2->Set(0);
=======
	Talon_Lift_2->SetSafetyEnabled(false);
	Talon_Lift_2->SetExpiration(0.100);
	Talon_Lift_2->Set(0);
>>>>>>> branch 'master' of https://github.com/tkdberger/3494_2016_repo.git
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
