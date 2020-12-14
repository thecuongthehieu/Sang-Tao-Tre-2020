/* Front-left motor */
#define m1a A0          //In1 L298n1
#define m1b A1          //In2 L298n1
#define m1P 4           //Enable PWM pin for 1st motor
#define m1EncodPinA 2   //encoder A pin
#define m1EncodPinB 8   //encoder B pin
volatile long m1EncoderPos = 0;

/* Front-right motor */
#define m2a A2          //In3 L298n1         
#define m2b A3          //In4 L298n1
#define m2P 5           //Enable PWM pin for 2nd motor
#define m2EncodPinA 3   //encoder A pin
#define m2EncodPinB 9   //encoder B pin
volatile long m2EncoderPos = 0;

/* Back-left motor */
#define m3a A4          //In1 L298n2
#define m3b A5          //In2 L298n2
#define m3P 6           //Enable PWM pin for 3nd motor
#define m3EncodPinA 18  //encoder A pin
#define m3EncodPinB 10  //encoder B pin        
volatile long m3EncoderPos = 0;

/* Back-right motor */
#define m4a A6          //In3 L298n2
#define m4b A7          //In4 L298n2
#define m4P 7           //Enable PWM pin for 4th motor
#define m4EncodPinA 19  //encoder A pin
#define m4EncodPinB 11  //encoder B pin 
volatile long m4EncoderPos = 0;

char data;

void setup() {
  Serial.begin(9600);    

  /* Front-left motor */
  pinMode(m1a, OUTPUT);  
  pinMode(m1b, OUTPUT);
  pinMode(m1P, OUTPUT);
  pinMode(m1EncodPinA, INPUT_PULLUP);                  
  pinMode(m1EncodPinB, INPUT_PULLUP);                  
  attachInterrupt(0, m1EncoderCnt, FALLING);               


  /* Front-right motor */
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(m2P, OUTPUT);
  pinMode(m2EncodPinA, INPUT_PULLUP);                  
  pinMode(m2EncodPinB, INPUT_PULLUP);                  
  attachInterrupt(1, m2EncoderCnt, FALLING);    


  /* Back-left motor */
  pinMode(m3a, OUTPUT);
  pinMode(m3b, OUTPUT);
  pinMode(m3EncodPinA, INPUT_PULLUP);                  
  pinMode(m3EncodPinB, INPUT_PULLUP);                  
  attachInterrupt(5, m3EncoderCnt, FALLING);    


  /* Back-right motor */
  pinMode(m4a, OUTPUT);
  pinMode(m4b, OUTPUT);
  pinMode(m4EncodPinA, INPUT_PULLUP);                  
  pinMode(m4EncodPinB, INPUT_PULLUP);                  
  attachInterrupt(4, m4EncoderCnt, FALLING);    

}

void loop() {
  //if serial value is received
  while (Serial.available() > 0) 
  {
    //save it to character 'data'
    data = Serial.read();
    //print it on serial monitor
    Serial.println(data);
    
    //if 'F' is recieved go forward
    if (data == 'F')
    {
      //at full speed
      forward(1);

    }
    //backward
    if (data == 'B')
    {
      backward(1);
    }
    //left
    if (data == 'L')
    {
      left(1);
    }
    //right
    if (data == 'R')
    {
      right(1);
    }
    //forward left
    if (data == 'G')
    {
      forward_left(1);
    }
    //forward right
    if (data == 'I')
    {
      forward_right(1);
    }
    //backward left
    if (data == 'H')
    {
      backward_left(1);
    }
    //backward right
    if (data == 'J')
    {
      backward_right(1);
    }
    //stop
    if ((data == 'S' || data == 'D'))
    {
      Stop();
    }
    //counter clockwise
    if (data == '0' || data == '1' || data == '2' || data == '3')
    {
      //at medium speed
      counter_clockwise(1);
    }
    //neutral
    if (data == '4' || data == '5' || data == '6')
    {
      neutral(1);
    }
    //clockwise
    if (data == '7' || data == '8' || data == '9' || data == 'q')
    {
      clockwise(1);
    }
  }


  
  
}

void m1EncoderCnt() {
  if (digitalRead(m1EncodPinB) == HIGH) {
    m1EncoderPos += 1;
  } else {
    m1EncoderPos -=1;
  }
}

void m2EncoderCnt() {
  if (digitalRead(m2EncodPinB) == HIGH) {
    m2EncoderPos += 1;
  } else {
    m2EncoderPos -=1;
  } 
}

void m3EncoderCnt() {
  if (digitalRead(m3EncodPinB) == HIGH) {
    m3EncoderPos += 1;
  } else {
    m3EncoderPos -=1;
  } 
}

void m4EncoderCnt() {
  if (digitalRead(m4EncodPinB) == HIGH) {
    m4EncoderPos += 1;
  } else {
    m4EncoderPos -=1;
  } 
}



/* Direction Control */
/** Setpoint: ...  xung/ms 
    Input: ... xung/ms
    Output: ... pwm
*/

void forward(int pmv) {

  
  analogWrite(m1P, 255);
  analogWrite(m2P, 255);
  analogWrite(m3P, 255);
  analogWrite(m4P, 255);
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  digitalWrite(m3a, HIGH);
  digitalWrite(m3b, LOW);
  digitalWrite(m4a, HIGH);
  digitalWrite(m4b, LOW);
}

void backward(int pmv) {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
}
void left(int pmv) {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
}
void right(int pmv) {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
}
void forward_left(int pmv) {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
}
void forward_right(int pmv) {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);  
}
void backward_left(int pmv) {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH); 
}
void backward_right(int pmv) {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
}
void Stop() {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
}
void counter_clockwise(int pmv) {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW); 
}
void neutral(int pmv) {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
}
void clockwise(int pmv) {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      Serial.println("CLOCKWISE");
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
}
