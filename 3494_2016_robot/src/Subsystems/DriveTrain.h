#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <ctime>
#include "AHRS.h"

class DriveTrain: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* LeftTalonMaster;
	CANTalon* LeftTalonFollower;
	CANTalon* LeftTalonFollower_2;

	CANTalon* RightTalonMaster;
	CANTalon* RightTalonFollower;
	CANTalon* RightTalonFollower_2;

//	AnalogGyro* gyro;

	AHRS *ahrs;
	bool NavXFail;
	float angle;
	double ramp;

	PowerDistributionPanel* pdp;
	float power = 1;
	//clock (commented out for now)
	//std::clock_t start;
	double timeElapsed= 0.0;
	float duration;

	float Rpulse, Lpulse;
//	int leftSign = 1;
//	int rightSign = 1;

public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(float Left_Axis, float Right_Axis);
	int PowerDistOutput();
	//int IndPowerOutput(int PDP_Channel);
	float PowerSide(int value);
	void ChangeGear(bool _gear);
	double GetPosition();
	//bool currentGear;
	int Encoder_Position();
	void ResetEncoders();
	bool TestDriveTrain(float _duration);
	void Fail_NavX(bool fail);
private:
	bool bCheck;
	float rightCurrent;
	float leftCurrent;

};

#endif
