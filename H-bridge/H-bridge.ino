#define motor_pin5 5
#define motor_pin6 6

void setup() 
{
  pinMode(motor_pin5, OUTPUT);
  pinMode(motor_pin6, OUTPUT);
}

void loop() 
{
  motor_run(120, 6);
}

void motor_run (int velocity, int direction) 
{
  //5 - против часовой, 6 - по часовой

  if (direction == 5) 
  {
    analogWrite(motor_pin5, velocity);
    pinMode(motor_pin5, OUTPUT);
    pinMode(motor_pin6, INPUT);
  }

  if (direction == 6)
  {
    analogWrite(motor_pin6, velocity);
    pinMode(motor_pin6, OUTPUT);
    pinMode(motor_pin5, INPUT);
  }
}