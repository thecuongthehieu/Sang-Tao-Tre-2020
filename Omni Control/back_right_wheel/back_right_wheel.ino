#define encodPinA1      19    // 2 3 18 19                       // Quadrature encoder A pin
#define encodPinB1      11    // 8 9 10 11                        // Quadrature encoder B pin
                             //
#define enA             7    // 4 5 6 7                        // PWM outputs to L298N H-Bridge motor driver module
#define in1             A6    // A0 A2 A4 A6
#define in2             A7    // A1 A3 A5 A7

volatile long encoderPos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(encodPinA1, INPUT_PULLUP);                  // quadrature encoder input A
  pinMode(encodPinB1, INPUT_PULLUP);                  // quadrature encoder input B
  attachInterrupt(4, encoder, FALLING);               // update encoder position 

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

}
void loop() {            
  Serial.println(encoderPos);
}

void encoder()  {                                     // pulse and direction, direct port reading to save cycles
  if (digitalRead(encodPinB1) == HIGH)    encoderPos++;             // if (digitalRead(encodPinB1)==HIGH)  count ++;
  else                      encoderPos--;             // if (digitalRead(encodPinB1)==LOW)   count --;
}
