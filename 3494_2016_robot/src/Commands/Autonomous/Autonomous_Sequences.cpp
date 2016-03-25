#include "Autonomous_Sequences.h"
#include "../../OI.h"
#include "Auto_Move_Tim.h"
#include "NewTurn.h"
#include "Auto_Roller_Lift.h"
#include "Turn.h"

Autonomous_Sequences::Autonomous_Sequences(int autoMode)
{

	SmartDashboard::init();
	one = false; // these are the autonomous states
	two = false; // this is an arbitrary number
	three = false;
	four = false;
	five = false;
	//test of reading from smart dashboard
	prefs = Preferences::GetInstance();
	backto = false;
	defense = "Bernie Sanders";
	if (autoMode == 1) // checks smart dashboard for what the user has selected the default is 1
	{
		auto1();
		one = true;
	}
	else if (autoMode == 2)
	{
		auto2();
		two = true;
	}
	else if (autoMode == 3)
	{
		auto3();
		three = true;
	}
	else if (autoMode == 4)
	{
		defense = prefs->GetString("defense", "Flowey the Flower");
		backto = prefs->GetBoolean("back to", false);
		auto4();
		four = true;
	}
	else if (autoMode == 5)
	{
		auto5();
		five = true;
	}
}

void Autonomous_Sequences::auto1() // autonomous sequence
{
	//AddParallel(new Solenoid_Roller_Set(true)); is an example of a parallel sequence
	//AddSequential(new Autonomous_Roller(1, 1)); is an example of a simple command call
	SmartDashboard::PutNumber("Auto1 State", 1); // displays during autnomous if the display is on
}

void Autonomous_Sequences::auto2()
{
	//turn and drive
//	AddSequential(new NewTurn(true, 2, 0.75));
	AddSequential(new Auto_Roller_Lift(.5));
	AddSequential(new Auto_Move_Tim(-.75,2));
	SmartDashboard::PutBoolean("Auto2 State", two);
}

void Autonomous_Sequences::auto3()
{
	SmartDashboard::PutBoolean("Auto3 State", three);
	AddParallel(new Auto_Roller_Lift(.5));
	AddSequential(new Auto_Move_Tim(-.75,1));
}

void Autonomous_Sequences::auto4()
{
	SmartDashboard::PutBoolean("Auto4 State", four);
	//this is the fancy one
	//TODO write better auto code
	if (backto){
		AddSequential(new Turn(180));
	}
	if (defense == "low bar" or "bar"){
			AddSequential(new Auto_Move_Tim(0.75, 5));
	}
	else if (defense == "ramparts"){
		//ramps
			AddSequential(new Auto_Move_Tim(0.75, 2.5));
			AddSequential(new Auto_Move_Tim(1, 3));
	}
	else if (defense == "moat"){
		//cross the moat in theory
			AddSequential(new Auto_Move_Tim(0.75, 2.5));
			AddSequential(new Auto_Move_Tim(1, 3));
			AddSequential(new Auto_Move_Tim(0.75, 1));
	}
	else {
		std::cout << "I'm amazed. " << defense << " is on the field and not a defense.";
	}
}

void Autonomous_Sequences::auto5()
{
	//please ensure we always have a blank auto program
	SmartDashboard::PutBoolean("Auto5 State", five);
}
void Autonomous_Sequences::Initialize() // pure virtual function needing defined doesn't have any other use
{

}

void Autonomous_Sequences::Execute() // pure virtual function needing defined
{

}

bool Autonomous_Sequences::IsFinished() // pure virtual function needing defined
{
	return true;// skip this warning because the function is not meant to be used
}

void Autonomous_Sequences::End() // pure virtual function needing defined
{

}

void Autonomous_Sequences::Interrupted() // pure virtual function needing defined
{

}
