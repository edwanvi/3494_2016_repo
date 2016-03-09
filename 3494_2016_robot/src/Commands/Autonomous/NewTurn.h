#ifndef NewTurn_H
#define NewTurn_H

#include "../../CommandBase.h"
#include "WPILib.h"

class NewTurn: public CommandBase
{
public:
	NewTurn(bool _left, double time, float _speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool left;
	double letime;
	float speed;
};

#endif
