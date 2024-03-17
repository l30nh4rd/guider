#include <Stepper.h>
#include <HalfStepper.h>

// change this to the number of steps on your motor
#define steps_per_revolution 1920
#define speed_rpm 1

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
HalfStepper stepper(steps_per_revolution, 1,3,2,4);

// the previous reading from the analog input

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(speed_rpm);
}

void loop() {
  //stepper.step(val - previous);
  stepper.step(steps_per_revolution);
}
