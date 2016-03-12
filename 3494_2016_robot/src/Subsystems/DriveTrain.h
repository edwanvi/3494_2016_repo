#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <ctime>
#include "AHRS.h"



class DriveTrain: public Subsystem
{
private:
	CANTalon* LeftTalonMaster;
	CANTalon* LeftTalonFollower;
	CANTalon* LeftTalonFollower_2;

	CANTalon* RightTalonMaster;
	CANTalon* RightTalonFollower;
	CANTalon* RightTalonFollower_2;


	AHRS *ahrs;

	float angle;


	PowerDistributionPanel* pdp;



	//////////
	DoubleSolenoid* solenoid_Shifter;
	float power = 1;

	float Rpulse;
	float Lpulse;

	//clock
	std::clock_t start;
	double timeElapsed= 0.0;
	double duration;

	int leftSign = 1;
	int rightSign = 1;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(float Left_Axis, float Right_Axis);
	int PowerDistOutput();
	//int IndPowerOutput(int PDP_Channel);
	float PowerSide(int value);
	void ChangeGear(bool _gear);
	double GetPosition();
	bool currentGear;
	int Encoder_Position();
	void ResetEncoders();
	bool TestDriveTrain(float _duration);
private:
	bool bCheck;
	float rightCurrent;
	float leftCurrent;
};

#endif
