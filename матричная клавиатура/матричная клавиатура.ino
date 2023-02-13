#define led_pin3 3
#define led_pin4 4
#define led_pin5 5
#define led_pin6 6

void setup() {
  Serial.begin(9600);
  pinMode(led_pin3, INPUT);
  pinMode(led_pin4, INPUT);
  pinMode(led_pin5, OUTPUT);
  pinMode(led_pin6, OUTPUT);
}

int val1;
int val3;
int val2;
int val4;
String result;

void loop() {
  val1 = 0;
  val3 = 0;
  val2 = 0;
  val4 = 0;
  result = "";
  pinMode(led_pin6, INPUT);
  pinMode(led_pin5, OUTPUT);
  digitalWrite(led_pin5, HIGH);
  if (digitalRead(led_pin3) == 1 && digitalRead(led_pin4) == 0)
  {
    result = "1 кнопка";
    val1 = 1;
  }
  if (digitalRead(led_pin4) == 1 && digitalRead(led_pin3) == 0)
  {
    result = "2 кнопка";
    val2 = 1;
  }
  if (digitalRead(led_pin4) == 1 && digitalRead(led_pin3) == 1)
  { 
    result = "1, 2 кнопка";
  }
  digitalWrite(led_pin5, LOW);
  pinMode(led_pin5, INPUT);  
  pinMode(led_pin6, OUTPUT);
  digitalWrite(led_pin6, HIGH);
  if (digitalRead(led_pin3) == 1 && digitalRead(led_pin4) == 0)
  {
    result = "3 кнопка";
    val3 = 1;
  }
  if (digitalRead(led_pin4) == 1 && digitalRead(led_pin3) == 0)
  {
    result = "4 кнопка";
    val4 = 1;
  }
  if (digitalRead(led_pin4) == 1 && digitalRead(led_pin3) == 1)
  { 
    result = "3, 4 кнопка";
  }  
  if (val3 == 1 && val1 == 1 && val2 == 0 && val4 == 0)
  { 
    result = "1, 3  кнопка";
  }
  if (val1 == 1 && val4 == 1 && val2 == 0 && val3 == 0)
  { 
    result = "1, 4  кнопка";
  }
  if (val2 == 1 && val3 == 1 && val1 == 0 && val4 == 0)
  { 
    result = "2, 3  кнопка";
  }
  if (val2 == 1 && val4 == 1 && val1 == 0 && val3 == 0)
  { 
    result = "2, 4  кнопка";
  }
  if (val1 == 1 && val2 == 1 && val3 == 1 && val4 == 0)
  { 
    result = "1, 2, 3  кнопка";
  }
  if (val1 == 1 && val2 == 1 && val4 == 1 && val3 == 0)
  { 
    result = "1, 2, 4  кнопка";
  }
  if (val1 == 1 && val3 == 1 && val4 == 1 && val2 == 0)
  { 
    result = "1, 3, 4  кнопка";
  }
  if (val2 == 1 && val3 == 1 && val4 == 1 && val1 == 0)
  { 
    result = "2, 3, 4  кнопка";
  }
  if (val2 == 1 && val3 == 1 && val4 == 1 && val1 == 1)
  { 
    result = "1, 2, 3, 4  кнопка";
  }
  if (val2 == 1 || val3 == 1 || val4 == 1 || val1 == 1){
    Serial.println(result);
  }
  digitalWrite(led_pin6, LOW);
  delay(500);
}