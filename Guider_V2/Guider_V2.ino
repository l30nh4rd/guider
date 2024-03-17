#include <Stepper.h>
#include <HalfStepper.h>

// speed in RPM
const int top_speed = 14; 
const float speed_rpm = 1;

// debug settings
const bool debug = false;

// motor config
const int steps_per_revolution = 2048; // too fast, --; too slow, ++
const float speed_adjust = 1.0;

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
HalfStepper stepper(steps_per_revolution, 1,3,2,4);


void setup() {
  // set the speed of the motor to speed_rpm RPMs
  stepper.setSpeed(speed_rpm * speed_adjust);
}

void loop() {
  //stepper.step(val - previous);
  stepper.step(steps_per_revolution*2);
  if (debug == true) {
    delay(1000);
  }
}
