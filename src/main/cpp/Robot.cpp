// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  m_intakeL.Set(ControlMode::PercentOutput, -1);
  m_intakeR.Set(ControlMode::PercentOutput, 1);
}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() 
{
  Robot::direction();
  Robot::arm();
}

//takes the joystick input and sets the direction sent to the drive function
void Robot::direction()
{
  float forward = m_joystick.GetRawAxis(0);
  float rotation = m_joystick.GetRawAxis(1);
  if (!m_joystick.GetRawButton(2))
  {
    rotation /= 1.5;
  }
  if (m_joystick.GetRawButton(3))
  {
    rotation *= 2;
  }
  // std::cout << "left motor " << forward-rotation << "\nright motor " <<
  // forward + rotation << "\n";
  if (forward > 0.2 || forward < -0.2 || rotation > 0.2 || rotation < -0.2)
  {
    drive(forward - rotation, forward + rotation);
  }
  else
  {
    drive(0, 0);
  }
}

//controlls the arm of the robot, currently just for the shooting mechanisum from an xbox controller
//left index trigger to shoot and right index trigger for intake
//the index trigger is the small button that your index finger rests on while holding the throttle
void Robot::arm()
{
  if(m_joystick.GetRawButton(20))
  {
    m_intakeL.Set(ControlMode::PercentOutput, 0.2);
    m_intakeR.Set(ControlMode::PercentOutput, -0.2);
  }
  if(m_joystick.GetRawButton(22))
  {
    m_intakeL.Set(ControlMode::PercentOutput, -intakeSpeed);
    m_intakeR.Set(ControlMode::PercentOutput, intakeSpeed);
  }
  if(!m_joystick.GetRawButton(20) && !m_joystick.GetRawButton(22))
  {
    m_intakeL.Set(ControlMode::PercentOutput, 0);
    m_intakeR.Set(ControlMode::PercentOutput, 0);
  }
}

//sets the motors on either ide to the variables that are sent to it
void Robot::drive(double left, double right)
{
  // setting motor speeds to parameters
  left *= (((-m_joystick.GetRawAxis(4)) + 1) / 2) +
          (0.2 * (1 - m_joystick.GetRawAxis(4)));
  right *= (((-m_joystick.GetRawAxis(4)) + 1) / 2);
  // if (m_pdp.GetCurrent(14) < 10 && m_pdp.GetCurrent(15) < 10 &&
  // m_pdp.GetCurrent(16) < 10 && m_pdp.GetCurrent(17) < 10)
  {
    m_driveMotorLBack.Set(ControlMode::PercentOutput, left);
    m_driveMotorLFront.Set(ControlMode::PercentOutput, left);
    m_driveMotorRBack.Set(ControlMode::PercentOutput, right);
    m_driveMotorRFront.Set(ControlMode::PercentOutput, right);
  }
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}





#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
