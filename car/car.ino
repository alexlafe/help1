int motorRight1 = 4; //направление
int motorRight2 = 5; //скорость
//56 СКОРОСТЬ
//47 НАПРАВЛЕНИЕ
int motorLeft1 = 6; //скорость
int motorLeft2 = 7; //направление

int pin_trig = 9;
int pin_echo = 10;

long duration = 0;
long duration_pre = 0;
long cm = 0;

int IPin = A0;

int control; // Управление двигателями.
int motorSpeed; // Управление скоростью.

bool status_stop = false;
bool status_forward = false;
bool status_left = false;
bool status_right = false;

void setup() {
  pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);

  pinMode (motorLeft1, OUTPUT);
  pinMode (motorLeft2, OUTPUT);

  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);

  Serial.begin (9600);
}

void loop()
{
  float volts = analogRead(IPin)*0.0048828125;
  float distance_left = 32*pow(volts,-1.10);
  
  duration_pre = duration;

  digitalWrite(pin_trig, LOW);
  delayMicroseconds(5);
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);
  duration = pulseIn(pin_echo, HIGH);
  float distance_forward = (duration / 2) / 29.1;
  Serial.println(distance_forward);
  delay(250);

  if (status_forward)
  {
    digitalWrite (motorLeft2, HIGH);
    analogWrite (motorLeft1, 250);
    digitalWrite (motorRight1, HIGH);
    analogWrite (motorRight2, 250);
  }

  if (status_right)
  {
    digitalWrite (motorLeft2, HIGH);
    analogWrite (motorLeft1, 250);
    digitalWrite (motorRight1, LOW);
    analogWrite (motorRight2, 150);
  }

  if (status_left)
  {
    digitalWrite (motorLeft2, LOW);
    analogWrite (motorLeft1, 120);
    digitalWrite (motorRight1, HIGH);
    analogWrite (motorRight2, 250);
  }

  if (distance_forward < 30)
  {
    status_stop = true;
    status_forward = false;
    status_right = false;
    status_left = false;

    if (distance_left < 30)
    {
      status_stop = false;
      status_forward = false;
      status_right = true;
      status_left = false;
    }
  }
  
  else if (distance_left > 30)
  {
    status_stop = false;
    status_forward = false;
    status_right = false;
    status_left = true;
  }

  else if (distance_left < 30 && distance_forward > 30)
  {
    status_stop = false;
    status_forward = true;
    status_right = false;
    status_left = false;
  }

  delay(500);
}