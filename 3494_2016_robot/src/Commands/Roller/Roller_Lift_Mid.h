#ifndef Roller_Lift_Mid_H
#define Roller_Lift_Mid_H

#include "../../CommandBase.h"
#include "../../RobotMap.h"
#include "WPILib.h"

class Roller_Lift_Mid: public CommandBase
{
private:
	AnalogInput* roller_down_sensor;
	double down_voltage;
public:
	Roller_Lift_Mid();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
