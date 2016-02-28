#include "WPILib.h"
#include "AHRS.h"
#include "Commands/Command.h"
#include "Commands/Autonomous/Autonomous_Sequences.h"
#include "Commands/Autonomous/Auto_Score.h"
#include "CommandBase.h"
#include "OI.h"


class Robot: public IterativeRobot
{
private:
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser *obstacle;
	SendableChooser *position;

	Command * autonomousSequence;
	Command * Auto_Score;

	AHRS *ahrs; /* Alternatives:  SPI::kMXP, I2C::kMXP or SerialPort::kUSB */

	void RobotInit()
	{
		SmartDashboard::init();
		CommandBase::init();
		obstacle = new SendableChooser();
		position = new SendableChooser();

		obstacle->AddDefault("Auto 1", new Autonomous_Sequences(1)); // adds the radio buttons for choosing in the smart dashboard
		obstacle->AddObject("Auto 2", new Autonomous_Sequences(2));
		obstacle->AddObject("Auto 3", new Autonomous_Sequences(3));
		obstacle->AddObject("Auto 4", new Autonomous_Sequences(4));
		obstacle->AddObject("Auto 5", new Autonomous_Sequences(5));
		obstacle->AddObject("Auto 6", new Autonomous_Sequences(6));
		obstacle->AddObject("Auto 7", new Autonomous_Sequences(7));
		obstacle->AddObject("Auto 8", new Autonomous_Sequences(8));
		position->AddDefault("Middle", new Auto_Score(1));
		position->AddObject("Right", new Auto_Score(2));
		position->AddObject("Left", new Auto_Score(3));



		//obstacle->AddObject("My Auto", new MyAutoCommand());
		SmartDashboard::PutData("Auto Modes", obstacle);
		SmartDashboard::PutData("Position", position);
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the obstacle code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable obstacle code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the obstacle code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the obstacle code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
		autonomousSequence = (Command*)obstacle->GetSelected();
		if (autonomousSequence != NULL)
			autonomousSequence->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousSequence != NULL)
			autonomousSequence->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)
