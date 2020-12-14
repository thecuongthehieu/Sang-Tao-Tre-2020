const int m1a = 12; //upper left 1st motor
const int m1b = 11;
const int m2a = 6; //upper right 2nd motor
const int m2b = 7;
const int m3a = 8; //lower left 3rd motor
const int m3b = 13;
const int m4a = 4; //lower right 4th motor
const int m4b = 2;
const int m1P = 9; //Enable PWM pin for 1st motor
const int m2P = 5;  //Enable PWM pin for 2nd motor
const int m3P = 10;  //Enable PWM pin for 3rd motor
const int m4P = 3;  //Enable PWM pin for 4th motor


char data;

void setup() {
  Serial.begin(9600);    //initialize serial @ 9600 baudrate
  pinMode(m1a, OUTPUT);  //defining pins
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(m3a, OUTPUT);
  pinMode(m3b, OUTPUT);
  pinMode(m4a, OUTPUT);
  pinMode(m4b, OUTPUT);

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
      analogWrite(m1P, 150);
      analogWrite(m2P, 150);
      analogWrite(m3P, 150);
      analogWrite(m4P, 150);
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
      analogWrite(m1P, 150);
      analogWrite(m2P, 150);
      analogWrite(m3P, 150);
      analogWrite(m4P, 150);
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
