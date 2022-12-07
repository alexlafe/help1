#define btn_pin 2
#define btn_pin2 3
#define btn_pin3 4
#define btn_pin4 5
#define btn_pin5 6
#define btn_pin6 7
#define btn_pin7 8
#define btn_pin8 9

void setup() {
  Serial.begin(115200);
  pinMode(btn_pin, INPUT);
  pinMode(btn_pin2, INPUT);
  pinMode(btn_pin3, INPUT);
  pinMode(btn_pin4, INPUT);
  pinMode(btn_pin5, INPUT);
  pinMode(btn_pin6, INPUT);
  pinMode(btn_pin7, INPUT);
  pinMode(btn_pin8, INPUT);
}

void loop() {
  int val = digitalRead(btn_pin);
  int val2 = digitalRead(btn_pin2);
  int val3 = digitalRead(btn_pin3);
  int val4 = digitalRead(btn_pin4);
  int val5 = digitalRead(btn_pin5);
  int val6 = digitalRead(btn_pin6);
  int val7 = digitalRead(btn_pin7);
  int val8 = digitalRead(btn_pin8);
  
  if (val == 1)
  {
    Serial.println("1");
  }
  if (val2 == 1)
  {
    Serial.println("2");
  }
  if (val3 == 1)
  {
    Serial.println("3");
  }
  if (val4 == 1)
  {
    Serial.println("4");
  }
  if (val5 == 1)
  {
    Serial.println("5");
  }
  if (val6 == 1)
  {
    Serial.println("6");
  }
  if (val7 == 1)
  {
    Serial.println("7");
  }
  if (val8 == 1)
  {
    Serial.println("8");
  }

  delay(100);
}