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
	float speed;
	float target;
public:
	Turn(float _turn);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
