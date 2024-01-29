// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <iostream>
#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include <ctre/phoenix.h>
#include <frc/XboxController.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;

  double intakeSpeed = 0.5;
void direction(){
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

  void drive(double left, double right)
{
  // setting motor speeds to parameters
  left *= -(((-m_joystick.GetRawAxis(4)) + 1) / 2) +
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

void arm()
{
  if(m_armControll.GetLeftBumper())
  {
    m_intakeL.Set(ControlMode::PercentOutput, intakeSpeed);
    m_intakeR.Set(ControlMode::PercentOutput, -intakeSpeed);
  }
  if(m_armControll.GetRightBumper())
  {
    m_intakeL.Set(ControlMode::PercentOutput, -intakeSpeed);
    m_intakeR.Set(ControlMode::PercentOutput, intakeSpeed);
  }
  if(m_armControll.GetXButton())
  {
    intakeSpeed = 0.5;
  }
  if(m_armControll.GetYButton())
  {
    intakeSpeed = 0.75;
  }
  if(m_armControll.GetBButton())
  {
    intakeSpeed = 0.1;
  }
}

  private:
  TalonFX m_driveMotorRFront{2};
  TalonFX m_driveMotorRBack{3};
  TalonFX m_driveMotorLFront{4};
  TalonFX m_driveMotorLBack{5};
  TalonFX m_intakeL{16};
  TalonFX m_intakeR{15};
  frc::Joystick m_joystick{0};
  frc::XboxController m_armControll{1};
};
