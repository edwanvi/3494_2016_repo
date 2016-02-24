#ifndef Lifting_H
#define Lifting_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/Robot_Lift.h"

class Lifting: public CommandBase
{
public:
	Lifting(bool _mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
