#ifndef RunRollers_H
#define RunRollers_H

#include "../CommandBase.h"
#include "Subsystems/Rollers.h"
#include "WPILib.h"

class RunRollers: public CommandBase
{
public:
	RunRollers(bool direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
