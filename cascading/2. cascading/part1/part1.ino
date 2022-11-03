#include <SoftwareSerial.h> 
SoftwareSerial mySerial(10, 11);

#define led_pin_2 2
#define led_pin_3 3
#define led_pin_4 4
#define led_pin_5 5
#define led_pin_6 6
#define led_pin_7 7
#define led_pin_8 8
#define led_pin_9 9

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600); 
  while (!Serial) { } 
  Serial.println("Начинаем работу!");

  pinMode(led_pin_2, OUTPUT);
  pinMode(led_pin_3, OUTPUT);
  pinMode(led_pin_4, OUTPUT);
  pinMode(led_pin_5, OUTPUT);
  pinMode(led_pin_6, OUTPUT);
  pinMode(led_pin_7, OUTPUT);
  pinMode(led_pin_8, OUTPUT);
  pinMode(led_pin_9, OUTPUT);
}

int first_part;
char second_part;
String number;

void loop() 
{   
  if (Serial.available() == 2)
  {
    first_part = Serial.read() - '0';
    second_part = Serial.read();
    Serial.println(first_part);
    Serial.println(second_part);

    mySerial.write(second_part);
    


    // number = Serial.readString();
    
    // if (number.length() == 2)
    // {
    //   first_part = number[0];
    //   second_part = number[1];
    // }
    // else if (number.length() == 1)
    // {
    //   first_part = "0";
    //   second_part = number;
    // }

    // Serial.println(first_part);
    // Serial.println(second_part);

    // mySerial.print(second_part);

    if (first_part == 1)
    {
      digitalWrite(led_pin_5, HIGH);
      digitalWrite(led_pin_3, HIGH);
      digitalWrite(led_pin_4, HIGH);
      digitalWrite(led_pin_6, HIGH);
      digitalWrite(led_pin_7, HIGH);
      digitalWrite(led_pin_8, HIGH);
    }
  }

  // if (mySerial.available())
  // {
  //   Serial.write(mySerial.read());
  // }
}
