#include <PID_v1.h>                                   // Thanks to Brett Beauregard for his nice PID library
#define encodPinA1      2                             // Quadrature encoder A pin
#define encodPinB1      8                             // Quadrature encoder B pin

#define enA             5                             // PWM outputs to L298N H-Bridge motor driver module
#define in1             A0
#define in2             A1


double kp =  10, ki = 100 , kd = 0 ,input = 0, output = 0, setpoint = 0;   // modify kp, ki and kd for optimal performance

volatile long encoderPos = 0;

double v;
long currTime, prevTime=0, loopTime;

PID myPID(&input, &output, &setpoint, kp, ki, kd, DIRECT);  // if motor will only run at full speed try 'REVERSE' instead of 'DIRECT'

void setup() {
  Serial.begin(9600);
  pinMode(encodPinA1, INPUT_PULLUP);                  // quadrature encoder input A
  pinMode(encodPinB1, INPUT_PULLUP);                  // quadrature encoder input B
  attachInterrupt(0, encoder, FALLING);               // update encoder position
  TCCR1B = TCCR1B & 0b11111000 | 1;                   // set 31KHz PWM to prevent motor noise

  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(1);
  myPID.SetOutputLimits(0, 255);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}
void loop() {
  encoderPos = 0;
  currTime = millis();

  delay(100);
 
  loopTime = currTime - prevTime; 
  prevTime = currTime;

  Serial.print("ep: ");
  Serial.print(encoderPos);
  Serial.print(" ");
  
  v = encoderPos / loopTime;

  Serial.print("pt: ");
  Serial.print(loopTime);
  Serial.print(" ");
                           
  setpoint = 6;                              	      // van toc mong muon xung/ms
  Serial.print("sp: ");
  Serial.print(setpoint);
  Serial.print(" ");
  
  input = v ;                                         // data from encoder

  Serial.print("ip: ");
  Serial.print(input);
  Serial.print(" ");
  
  myPID.Compute();                                    // calculate new output
  pwmOut(output);                                     // drive L298N H-Bridge module


  Serial.print("op: ");
  Serial.print(output);
  Serial.print(" ");

  Serial.println();
}


void pwmOut(int pwmOut) {                                // to H-Bridge board 
  if (pwmOut > 0) {
    analogWrite(enA, pwmOut);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);                                         
  }
}



void encoder()  {                                     // pulse and direction, direct port reading to save cycles
  if (PINB & 0b00000001)    encoderPos++;             // if (digitalRead(encodPinB1)==HIGH)  count ++;
  else                      encoderPos--;             // if (digitalRead(encodPinB1)==LOW)   count --;
}
