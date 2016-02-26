#include "CommandBase.h"


// Initialize a single static instance of all of your subsystems to NULL
//std::unique_ptr<ExampleSubsystem> CommandBase::examplesubsystem;
OI* CommandBase::oi = NULL;
DriveTrain* CommandBase::driveTrain = NULL;
Rollers* CommandBase::roller = NULL;
Robot_Lift* CommandBase::lift = NULL;
CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	//examplesubsystem.reset(new ExampleSubsystem());


	roller = new Rollers();
	oi = new OI();
	driveTrain = new DriveTrain();
	lift = new Robot_Lift();
}

void autonomous(bool mode)
{
	//Autonomous = mode;
}
