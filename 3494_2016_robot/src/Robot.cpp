#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/Autonomous/Autonomous_Sequences.h"
#include "CommandBase.h"
#include "OI.h"

class Robot: public IterativeRobot
{
private:
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser *chooser;
	Command * autonomousSequence;



	void RobotInit()
	{
		SmartDashboard::init();
		CommandBase::init();
		chooser = new SendableChooser();
		chooser->AddDefault("Auto 1", new Autonomous_Sequences(1)); // adds the radio buttons for choosing in the smart dashboard
		chooser->AddObject("Auto 2", new Autonomous_Sequences(2));
		chooser->AddObject("Auto 3", new Autonomous_Sequences(3));
		chooser->AddObject("Auto 4", new Autonomous_Sequences(4));
		chooser->AddObject("Auto 5", new Autonomous_Sequences(5));

		//chooser->AddObject("My Auto", new MyAutoCommand());
		SmartDashboard::PutData("Auto Modes", chooser);
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
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
		autonomousSequence = (Command*)chooser->GetSelected();
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

