#include "Autonomous_Sequences.h"
#include "../../OI.h"


Autonomous_Sequences::Autonomous_Sequences(int autoMode)
{

	SmartDashboard::init();
	one = false;
	two = false;
	three = false;
	four = false;
	if (autoMode == 1 )
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
		auto4();
		four = true;
	}
	else if (autoMode == 5)
	{
		auto5();
		five = true;
	}
}

void Autonomous_Sequences::auto1()
{
	//AddParallel(new Solenoid_Roller_Set(true)); is an example of a parallel sequence
	//AddSequential(new Autonomous_Roller(1, 1)); is an example
	SmartDashboard::PutBoolean("Auto1 State", one);
}

void Autonomous_Sequences::auto2()
{

	SmartDashboard::PutBoolean("Auto2 State", two);
}

void Autonomous_Sequences::auto3()
{


	SmartDashboard::PutBoolean("Auto3 State", three);
}

void Autonomous_Sequences::auto4()
{


	SmartDashboard::PutBoolean("Auto4 State", four);
}

void Autonomous_Sequences::auto5()
{

	SmartDashboard::PutBoolean("Auto5 State", five);
}
void Autonomous_Sequences::Initialize()
{


}

void Autonomous_Sequences::Execute()
{

}

bool Autonomous_Sequences::IsFinished()
{

}

void Autonomous_Sequences::End()
{

}

void Autonomous_Sequences::Interrupted()
{


}
