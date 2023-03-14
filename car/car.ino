int motorRight1 = 4;       // Правый мотор.
int motorRight2 = 5;
//56 СКОРОСТЬ
//47 НАПРАВЛЕНИЕ
int motorLeft1 = 6;        // Левый мотор.
int motorLeft2 = 7;

int pin_trig = 9;
int pin_echo = 10;

long duration = 0;
long duration_pre = 0;
long cm = 0;

int IPin = A0;

int control;               // Управление двигателями.
int motorSpeed;            // Управление скоростью.

void setup() {
  pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);

  pinMode (motorLeft1, OUTPUT);
  pinMode (motorLeft2, OUTPUT);

  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);

  digitalWrite(pin_trig, LOW);
  delayMicroseconds(5);
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);
  duration = pulseIn(pin_echo, HIGH);

  Serial.begin (9600);
}

void rotate_right()
{
    digitalWrite (motorLeft2, HIGH);
    analogWrite (motorLeft1, 250);
    digitalWrite (motorRight1, HIGH);
    analogWrite (motorRight2, 0);
}

void rotate_left()
{
    digitalWrite (motorLeft2, HIGH);
    analogWrite (motorLeft1, 0);
    digitalWrite (motorRight1, HIGH);
    analogWrite (motorRight2, 250);
}

void loop()
{
  float volts = analogRead(IPin)*0.0048828125;
  float distance = 32*pow(volts,-1.10);
  Serial.println(distance);
  
  duration_pre = duration;

  digitalWrite(pin_trig, LOW);
  delayMicroseconds(5);
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);
  duration = pulseIn(pin_echo, HIGH);
  cm = (duration / 2) / 29.1;
  Serial.println(cm);
  delay(250);

  if (cm < 30)
  {
    digitalWrite (motorLeft2, HIGH);
    analogWrite (motorLeft1, 0);
    digitalWrite (motorRight1, HIGH);
    analogWrite (motorRight2, 0);
    if (distance < 30)
    {
      rotate_right();
    }
  }
  
  else if (cm > 30 && distance > 30)
  {
    Serial.println("fkfkf");
    digitalWrite (motorLeft2, HIGH);
    analogWrite (motorLeft1, 0);
    digitalWrite (motorRight1, HIGH);
    analogWrite (motorRight2, 0);

    rotate_left();
  }
  else if (distance < 30 && cm > 30)
  {
    digitalWrite (motorLeft2, HIGH);
    analogWrite (motorLeft1, 250);
    digitalWrite (motorRight1, HIGH);
    analogWrite (motorRight2, 250);
  }
}


