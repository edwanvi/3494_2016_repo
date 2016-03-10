#include "Roller_Lift_Mid.h"
#include "../../Subsystems/Rollers.h"

Roller_Lift_Mid::Roller_Lift_Mid()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(roller);
	roller_down_sensor = new AnalogInput(ROLLER_DOWN);
	down_voltage = 0;
}

// Called just before this Command runs the first time
void Roller_Lift_Mid::Initialize()
{
	SmartDashboard::init();
}

// Called repeatedly when this Command is scheduled to run
void Roller_Lift_Mid::Execute()
{

	SmartDashboard::PutNumber("RollerDown", roller_down_sensor->GetVoltage());
	down_voltage = roller_down_sensor->GetVoltage();
	roller->Roller_Lift(-0.75);

}

// Make this return true when this Command no longer needs to run execute()
bool Roller_Lift_Mid::IsFinished()
{

	if ( down_voltage >= 4.9 || oi->GetSelect() )
	{
	roller->Roller_Lift(0);
	return true;
	}
	else
	{


		return false;
	}

}

// Called once after isFinished returns true
void Roller_Lift_Mid::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Roller_Lift_Mid::Interrupted()
{

}
