// rxPin = 0;
// txPin = 1;
#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(0, 1);

int motorRight1 = 4;       // Правый мотор.
int motorRight2 = 5;

int motorLeft1 = 6;        // Левый мотор.
int motorLeft2 = 7;

int control;               // Управление двигателями.
int motorSpeed;            // Управление скоростью.

void setup() {
  pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);

  pinMode (motorLeft1, OUTPUT);
  pinMode (motorLeft2, OUTPUT);

  Serial.begin(115200);
  mySerial.begin(115200);
}

void stop()
{
  digitalWrite (motorLeft2, HIGH);
  analogWrite (motorLeft1, 0);
  digitalWrite (motorRight1, HIGH);
  analogWrite (motorRight2, 0);
}

void forward()
{
  digitalWrite (motorLeft2, HIGH);
  analogWrite (motorLeft1, 250);
  digitalWrite (motorRight1, HIGH);
  analogWrite (motorRight2, 250);
}

void backward()
{
  digitalWrite (motorLeft2, LOW);
  analogWrite (motorLeft1, 250);
  digitalWrite (motorRight1, LOW);
  analogWrite (motorRight2, 250);
}

void right()
{
    digitalWrite (motorLeft2, HIGH);
    analogWrite (motorLeft1, 250);
    digitalWrite (motorRight1, HIGH);
    analogWrite (motorRight2, 0);
}

void left()
{
    digitalWrite (motorLeft2, HIGH);
    analogWrite (motorLeft1, 0);
    digitalWrite (motorRight1, HIGH);
    analogWrite (motorRight2, 250);
}

void loop()
{
  if (mySerial.available() > 0)
  {
    //Serial.print((byte)mySerial.read(), HEX);
    //Serial.print(" ");

    byte message = Serial.read();
    mySerial.println(message);

    if (message == 's')
    {
      stop();
    }
    else if (message == 'f')
    {
      forward();
    }
    else if (message == 'b')
    {
      backward();
    }
    else if (message == 'r')
    {
      right();
    }
    else if (message == 'l')
    {
      left();
    }
  }
}


