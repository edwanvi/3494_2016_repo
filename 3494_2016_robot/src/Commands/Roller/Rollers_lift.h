#ifndef Rollers_lift_H
#define Rollers_lift_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Rollers_lift: public CommandBase
{
private:
 float roller_lift_magnitude;
public:
	Rollers_lift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
