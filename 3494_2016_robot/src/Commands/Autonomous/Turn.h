#ifndef Turn_H
#define Turn_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Turn: public CommandBase
{
public:
	Turn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
