#include <SoftwareSerial.h>

#define enA 5
#define in1 6
#define in2 7

void setup() {

                                                                     Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void loop() {
  int potValue = analogRead(A0); // Read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  analogWrite(enA, 255); // Send PWM signal to L298N Enable pin
  Serial.println(pwmOutput);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(20);
}
