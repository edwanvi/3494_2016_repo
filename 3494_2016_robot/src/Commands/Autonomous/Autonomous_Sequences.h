#ifndef Autonomous_Sequences_H
#define Autonomous_Sequences_H

#include "../../CommandBase.h"
#include "../../OI.h"
#include "WPILib.h"
#include "Commands/CommandGroup.h"

class Autonomous_Sequences: public CommandGroup
{
private:
	void auto1();
	void auto2();
	void auto3();
	void auto4();
	void auto5();
	bool one,two,three,four,five;
public:
	Autonomous_Sequences(int autoMode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
