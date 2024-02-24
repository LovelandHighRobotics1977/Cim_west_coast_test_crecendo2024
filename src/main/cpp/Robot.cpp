// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() 
{
  //sets the robot to brake when it starts
  m_driveMotorLBack.SetNeutralMode(Brake);
  m_driveMotorLFront.SetNeutralMode(Brake);
  m_driveMotorRBack.SetNeutralMode(Brake);
  m_driveMotorRFront.SetNeutralMode(Brake);
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() 
{
  //drive(-0.5, 0.5);
}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() 
{
  if(Joystick)
  {
    if(m_joystick.GetRawButton(12))
    {
      Robot::JoystickDirection();
      Robot::JoystickArm();
    }
    else
    {
      drive((-m_joystick.GetRawAxis(4)+1)/2, (-m_joystick.GetRawAxis(4)+1)/2);
      JoystickArm();
    }
  }
  else
  {
    XboxDirection();
  }
}

//takes the joystick input and sets the direction sent to the drive function
//also uses the M1, 2, and 3 mode switch on the throttle to change from coast to break mode
//M1 is break, and the other two are coast
void Robot::JoystickDirection()
{
  float forward = m_joystick.GetRawAxis(0);
  float rotation = m_joystick.GetRawAxis(1);
  rotation /= 2;
  if (forward > 0.2 || forward < -0.2 || rotation > 0.2 || rotation < -0.2)
  {
    drive(forward - rotation, forward + rotation);
  }
  else
  {
    drive(0, 0);
  }
  if(m_joystick.GetRawButton(9))
  {
    m_driveMotorLBack.SetNeutralMode(Brake);
    m_driveMotorLFront.SetNeutralMode(Brake);
    m_driveMotorRBack.SetNeutralMode(Brake);
    m_driveMotorRFront.SetNeutralMode(Brake);
  }
  else
  {
    m_driveMotorLBack.SetNeutralMode(Coast);
    m_driveMotorLFront.SetNeutralMode(Coast);
    m_driveMotorRBack.SetNeutralMode(Coast);
    m_driveMotorRFront.SetNeutralMode(Coast);
  }
}

//uses the two Y positions from the Xbox sticks to drive the robot. 
//the right bumper Button changes the speed
void Robot::XboxDirection()
{
  drive(-m_armControll.GetLeftY() * DriveSpeed, m_armControll.GetRightY() * (DriveSpeed-(0.01 * DriveSpeed)));
  /*
  if(m_armControll.GetRightBumper())
  {
    DriveSpeed = 0.3;
  }
  else
  {
    DriveSpeed = 0.8;
  }
  */
}

//uses the xbox controller to controll the arm
//the y button launces at full speed, the x button is for the amp, and the A button is for the intake
void Robot::XboxArm()
{
  if(m_armControll.GetAButton())
  {
    m_intakeL.Set(ControlMode::PercentOutput, intakeSpeed);
    m_intakeR.Set(ControlMode::PercentOutput, -intakeSpeed);
  }
  if(m_armControll.GetXButton())
  {
    m_intakeL.Set(ControlMode::PercentOutput, -ampSpeed);
    m_intakeR.Set(ControlMode::PercentOutput, ampSpeed);
  }
  if(m_armControll.GetYButton())
  {
    m_intakeL.Set(ControlMode::PercentOutput, -shootSpeed);
    m_intakeR.Set(ControlMode::PercentOutput, shootSpeed);
  }
  
  if(!m_armControll.GetAButton() && !m_armControll.GetXButton() && !m_armControll.GetYButton())
  {
    m_intakeL.Set(ControlMode::PercentOutput, 0);
    m_intakeR.Set(ControlMode::PercentOutput, 0);
  }
}


//controlls the arm of the robot, currently just for the shooting mechanisum from the saitel X45 controllers
//left index trigger to shoot for the amp and right index trigger for intake
//if you pull the trigger up, that is for shooting in the higer target
//the index trigger is the small button that your index finger rests on while holding the throttle
//the speed for both parts is controlled by the upper knob
void Robot::JoystickArm()
{
  shootSpeed = (m_joystick.GetRawAxis(2)+1)/2;
  ampSpeed = (m_joystick.GetRawAxis(2)+1)/4;
  //if (m_pdp.GetCurrent(15) < 10 && m_pdp.GetCurrent(2) < 10)
  {
    if(m_joystick.GetRawButton(20))
    {
      m_intakeL.Set(ControlMode::PercentOutput, intakeSpeed);
      m_intakeR.Set(ControlMode::PercentOutput, -intakeSpeed);
    }
    if(m_joystick.GetRawButton(22))
    {
      m_intakeL.Set(ControlMode::PercentOutput, -ampSpeed);
      m_intakeR.Set(ControlMode::PercentOutput, ampSpeed);
    }
    if(m_joystick.GetRawButton(19))
    {
      m_intakeL.Set(ControlMode::PercentOutput, -shootSpeed);
      m_intakeR.Set(ControlMode::PercentOutput, shootSpeed);
  }
  }
  
  if(!m_joystick.GetRawButton(20) && !m_joystick.GetRawButton(22) && !m_joystick.GetRawButton(19))
  {
    m_intakeL.Set(ControlMode::PercentOutput, 0);
    m_intakeR.Set(ControlMode::PercentOutput, 0);
  }
}

//sets the motors on either ide to the variables that are sent to it
void Robot::drive(double left, double right)
{
  //if a joystick is present, sets the speed to the throttle
  if(Joystick)
  {
    //sets throttle for the Saitek X45 joysticks
    if(X45)
    {
      left *= (((-m_joystick.GetRawAxis(4)) + 1) / 2) +
              (0.2 * (1 - m_joystick.GetRawAxis(4)));
      right *= (((-m_joystick.GetRawAxis(4)) + 1) / 2);
    }
    //sets the speed for the logitech X3D Joysticks
    else
    {
      left *= (((-m_joystick.GetRawAxis(3)) + 1) / 2) +
              (0.2 * (1 - m_joystick.GetRawAxis(3)));
      right *= (((-m_joystick.GetRawAxis(3)) + 1) / 2);
    }
  }
  //checks the current on the PDH channel that each motor is on before letting them drive
  if(m_pdp.GetCurrent(12) < 10 && m_pdp.GetCurrent(15) < 10
   && m_pdp.GetCurrent(0) < 10 && m_pdp.GetCurrent(3) < 10)
   {
    m_driveMotorLBack.Set(ControlMode::PercentOutput, left);
    m_driveMotorLFront.Set(ControlMode::PercentOutput, left);
    m_driveMotorRBack.Set(ControlMode::PercentOutput, right);
    m_driveMotorRFront.Set(ControlMode::PercentOutput, right);
   }
   //if the current is too high, it wont let the motors drive
   else
   {
    m_driveMotorLBack.Set(ControlMode::PercentOutput, 0);
    m_driveMotorLFront.Set(ControlMode::PercentOutput, 0);
    m_driveMotorRBack.Set(ControlMode::PercentOutput, 0);
    m_driveMotorRFront.Set(ControlMode::PercentOutput, 0);
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
