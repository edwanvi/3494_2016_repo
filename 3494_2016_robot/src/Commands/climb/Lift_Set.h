#ifndef Lift_Set_H
#define Lift_Set_H

#include "../../CommandBase.h"
#include "WPILib.h"


class Lift_Set: public CommandBase
{
private:
	bool mode;
public:
	Lift_Set(bool _mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
