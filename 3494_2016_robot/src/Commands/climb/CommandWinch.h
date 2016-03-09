#ifndef CommandWinch_H
#define CommandWinch_H

#include "../../CommandBase.h"
#include "WPILib.h"

class CommandWinch: public CommandBase
{
public:
	CommandWinch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
