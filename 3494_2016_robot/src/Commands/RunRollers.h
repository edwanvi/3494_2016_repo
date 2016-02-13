#ifndef RunRollers_H
#define RunRollers_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/Rollers.h"

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
