#define led_pin3 3
#define led_pin4 4
#define led_pin5 5
#define led_pin6 6

void setup()
{
  pinMode(led_pin3, OUTPUT);
  pinMode(led_pin4, OUTPUT);
  pinMode(led_pin5, OUTPUT);
  pinMode(led_pin6, OUTPUT);
}

void led_one()
{
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, HIGH);
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, LOW);
}

void led_two()
{
  digitalWrite(led_pin3, HIGH);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, LOW);
}

void led_three()
{
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, HIGH);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, HIGH);
}

void led_four()
{
  digitalWrite(led_pin3, HIGH);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, HIGH);
}

void destroy()
{
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, LOW);
}

void loop()
{
  led_one();
  delay(1000);
  destroy();
  delay(500);

  led_two();
  delay(1000);
  destroy();
  delay(500);

  led_three();
  delay(1000);
  destroy();
  delay(500);

  led_four();
  delay(1000);
  destroy();
  delay(500);
}
