#ifndef Roller_Check_H
#define Roller_Check_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Roller_Check: public CommandBase
{
private:
	float test_time;
public:
	Roller_Check(float _time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
