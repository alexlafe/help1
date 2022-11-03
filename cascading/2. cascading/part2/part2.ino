

#define led_pin_2 2
#define led_pin_3 3
#define led_pin_4 4
#define led_pin_5 5
#define led_pin_6 6
#define led_pin_7 7
#define led_pin_8 8
#define led_pin_9 9

void setup() 
{ 
  Serial.begin(9600);
 
  while (!Serial) { } 


  pinMode(led_pin_2, OUTPUT);
  pinMode(led_pin_3, OUTPUT);
  pinMode(led_pin_4, OUTPUT);
  pinMode(led_pin_5, OUTPUT);
  pinMode(led_pin_6, OUTPUT);
  pinMode(led_pin_7, OUTPUT);
  pinMode(led_pin_8, OUTPUT);
  pinMode(led_pin_9, OUTPUT);
}

int second_part;

void loop() 
{
  if (Serial.available() > 0)
  {
    second_part = Serial.read() - '0';

    if (second_part == 1)
    {
      digitalWrite(led_pin_5, HIGH);
      digitalWrite(led_pin_3, HIGH);
      digitalWrite(led_pin_4, HIGH);
      digitalWrite(led_pin_6, HIGH);
      digitalWrite(led_pin_7, HIGH);
      digitalWrite(led_pin_8, HIGH);
    }
  }

  
}