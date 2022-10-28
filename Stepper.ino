//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRev = 2038;


// Pin IN1-IN3-IN2-IN4 
Stepper myStepper = Stepper(stepsPerRev, 19, 18, 5, 21);

void setup() {
}

void loop() {
  // Rotate Clockwise  at 10 RPM
  myStepper.setSpeed(10);
  myStepper.step(stepsPerRevolution);
  delay(1000);
  
  // Rotate Counter Clockwaise at 10 RPM
  myStepper.setSpeed(10);
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
