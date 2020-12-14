#define enA 5
#define in1 A0
#define in2 A1


#define encodPinA1      2                             // Quadrature encoder A pin
#define encodPinB1      8                             // Quadrature encoder B pin

volatile long encoderPos = 0;

long currTime, prevTime=0, loopTime;
double v = 0;

void setup() {
  Serial.begin(9600);
  pinMode(encodPinA1, INPUT_PULLUP);                  // quadrature encoder input A
  pinMode(encodPinB1, INPUT_PULLUP);                  // quadrature encoder input B
  attachInterrupt(0, encoder, FALLING);               // update encoder position 

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  analogWrite(enA, 255); 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

}
void loop() {            
//  encoderPos = 0;
//  currTime = millis();
//
//  delay(100);
// 
//  loopTime = currTime - prevTime; 
//  prevTime = currTime;
//  
//  v = encoderPos / loopTime;

  Serial.println(encoderPos);
}

void encoder()  {                                     // pulse and direction, direct port reading to save cycles
  if (PINB & 0b00000001)    encoderPos++;             // if (digitalRead(encodPinB1)==HIGH)  count ++;
  else                      encoderPos--;             // if (digitalRead(encodPinB1)==LOW)   count --;
}
