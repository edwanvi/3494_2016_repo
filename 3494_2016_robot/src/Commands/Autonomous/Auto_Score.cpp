#include "Auto_Score.h"

Auto_Score::Auto_Score(int position)
{
	Position = position;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

void Auto_Score::trigger()
{
	if (Position == 1)
	{
		middle();
	}
	else if (Position == 2)
	{
		right();
	}
	else if (Position == 3)
	{
		left();
	}

}

void Auto_Score::middle()
{

}

void Auto_Score::right()
{

}

void Auto_Score::left()
{

}


// Called just before this Command runs the first time
void Auto_Score::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Auto_Score::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Auto_Score::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Auto_Score::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Auto_Score::Interrupted()
{

}
