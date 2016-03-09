#ifndef reset_encoders_H
#define reset_encoders_H

#include "../../CommandBase.h"
#include "WPILib.h"

class reset_encoders: public CommandBase
{
public:
	reset_encoders();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
