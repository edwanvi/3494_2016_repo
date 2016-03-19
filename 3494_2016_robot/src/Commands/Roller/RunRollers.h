#ifndef RunRollers_H
#define RunRollers_H

#include "../../CommandBase.h"
#include "Rollers_lift.h"
#include "../../OI.h"
#include "WPILib.h"
#include "../../Subsystems/Rollers.h"

class RunRollers: public CommandBase
{
private:
int mode;
public:
	RunRollers();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
