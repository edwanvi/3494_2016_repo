#ifndef Lifting_H
#define Lifting_H

#include "../CommandBase.h"
#include "WPILib.h"

class Lifting: public CommandBase
{
public:
	Lifting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
