#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem
{
private:
	CANTalon* LeftTalonMaster;
	CANTalon* LeftTalonFollower;
	CANTalon* LeftTalonFollower_2;

	CANTalon* RightTalonMaster;
	CANTalon* RightTalonFollower;
	CANTalon* RightTalonFollower_2;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(float Left_Axis, float Right_Axis);
};

#endif
