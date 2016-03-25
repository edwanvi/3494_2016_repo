#ifndef Auto_Roller_Lift_H
#define Auto_Roller_Lift_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Auto_Roller_Lift: public CommandBase
{
private:
	float speed;
	float time;
public:
	Auto_Roller_Lift(float time_);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
