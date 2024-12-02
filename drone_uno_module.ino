#include <Servo.h>

//   N
// 2   1
// 3   4

Servo ESC1; //ccw
Servo ESC2; //cw
Servo ESC3; //ccw
Servo ESC4; //cw

int v1;
int v2;
int v3;
int v4;
     

void setup() 
{
 
  ESC1.attach(6,1000,2000); 
  ESC2.attach(9,1000,2000);
  ESC3.attach(10,1000,2000);
  ESC4.attach(11,1000,2000);

  Serial.begin(9600);

  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}

void loop() 
{

  if(digitalRead(2) == HIGH)
  {
    up();
  }
  if(digitalRead(3) == HIGH)
  {
    forward();
  }
  if(digitalRead(4) == HIGH)
  {
    back();
  }
  if(digitalRead(5) == HIGH)
  {
    left();
  }
  if(digitalRead(12) == HIGH)
  {
    right();
  }
  if(digitalRead(13) == HIGH)
  {
    stop();
  }
  

  v1 = map(v1, 0, 1023, 0, 180); 
  v2 = map(v2, 0, 1023, 0, 180); 
  v3 = map(v3, 0, 1023, 0, 180); 
  v4 = map(v4, 0, 1023, 0, 180); 

  Serial.print(v1);
  Serial.print(" ");
  Serial.print(v2);
  Serial.print(" ");
  Serial.print(v3);
  Serial.print(" ");
  Serial.println(v4);
  
  ESC1.write(v1);
  ESC2.write(v2);
  ESC3.write(v3);
  ESC4.write(v4);
}

//up fwd back left right stop

//2 up 22
//3 fwd 23
//4 back 24
//5 left 25
//12 right 26
//13 stop 27

void up() // all high
{
  Serial.print("forward");
  v1=500;
  v2=500;
  v3=1023;
  v4=1023;
}

void forward() // 3 4 high
{
  Serial.print("back");
  v1=1023;
  v2=1023;
  v3=1023;
  v4=1023;
  
}

void back() // 1 2 high
{
  Serial.print("up");
  v1=1023;
  v2=1023;
  v3=500;
  v4=500;
}

void left() // 1 4 high
{
  Serial.print("left");
  v1=500;
  v2=1023;
  v3=1023;
  v4=500;
}

void right() // 2 3 high
{
  Serial.print("right");
  v1=1023;
  v2=500;
  v3=500;
  v4=1023;
}

void stop() // all low
{
  Serial.print("stop");
  v1=0;
  v2=0;
  v3=0;
  v4=0;
}




























