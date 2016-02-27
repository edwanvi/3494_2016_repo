#ifndef SystemsCheck_H
#define SystemsCheck_H

#include "../CommandBase.h"
#include "WPILib.h"

class SystemsCheck: public CommandBase
{
public:
	SystemsCheck();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
