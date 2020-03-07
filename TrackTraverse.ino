#include <RedBot.h>
#include <RedBotSoftwareSerial.h>

 // Hello World :)
 // Hello WOrld More More Git test :)
RedBotMotors Motor; // declare motor object

#define LeftMotorSpeed (50) // Set Left Motor to  roughly Half Speed
#define RightMotorSpeed (50) // Set Right Motor to roughly Half Speed

/*
 * Try 90 Later when actually displaying
*/

void setup()
{
  // put your setup code here, to run once:

}

void loop()
{
  // put your main code here, to run repeatedly:

  RedBotSensor RightSensor = RedBotSensor(A7); // RedBot Sensor Object is Assigned to Right Sensor
  RedBotSensor LeftSensor = RedBotSensor(A3); // Redbot Sensor Object is Assigned to Left Sensor

  if ((LeftSensor.read() > 850) && (RightSensor.read() < 850))
  {
    // Drive Forward
    Motor.rightMotor(RightMotorSpeed);
    Motor.leftMotor(-LeftMotorSpeed);
  }
  else if ((LeftSensor.read() < 850) && (RightSensor.read() < 850))
  {
    // Left Wheel Turns off Right Wheel turns on
    // Turn Left
    Motor.rightMotor(RightMotorSpeed);
    Motor.leftMotor(0);
  }
  else if((LeftSensor.read() > 850) && (RightSensor.read()))
  {
    // Left Wheel Turns On Right Wheel Turns on
    // Turn Left
   Motor.rightMotor(0);
   Motor.leftMotor(-LeftMotorSpeed);
  }
  delay (10);
}
