// 28BYJ-48, using an NTE2019 darlington (similar to uln2003) driver
//   Blue   - 28BYJ48 pin 1 <-- 2019 <-- arduino pin 8
//   Pink   - 28BYJ48 pin 2 <-- 2019 <-- arduino pin 9
//   Yellow - 28BYJ48 pin 3 <-- 2019 <-- arduino pin 10
//   Orange - 28BYJ48 pin 4 <-- 2019 <-- arduino pin 11
//   Red    - 28BYJ48 pin 5 <-- vcc

const int steps_per_revolution = 2048;
const float speed_rpm = 0.1;  // not absolutely perfect, but probably usable with 0.1 rpm

float steps_per_second = steps_per_revolution * (speed_rpm / 60);
float delay_time = 1 / (steps_per_second * 2) * 1000; // in milliseconds


byte patterns[8] = {
  0b00001000,
  0b00001100,
  0b00000100,
  0b00000110,
  0b00000010,
  0b00000011,
  0b00000001,
  0b00001001,
};

void setup() {
  pinMode(1, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  for (int i = 7; i >= 0; i--) {
    // half step per iteration 
    digitalWrite(1, bitRead(patterns[i], 0));
    digitalWrite(2, bitRead(patterns[i], 1));
    digitalWrite(3, bitRead(patterns[i], 2));
    digitalWrite(4, bitRead(patterns[i], 3));
    delay(delay_time);
  }
}
