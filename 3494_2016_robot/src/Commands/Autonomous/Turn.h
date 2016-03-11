#ifndef Turn_H
#define Turn_H

#include "../../CommandBase.h"
#include "WPILib.h"
#include "AHRS.h"


class Turn: public CommandBase
{
private:
	AHRS *ahrs;

	float angle;
public:
	Turn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
