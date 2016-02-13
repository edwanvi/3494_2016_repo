#ifndef Roll_H
#define Roll_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/Rollers.h"

class Roll: public CommandBase
{
public:
	Roll();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
