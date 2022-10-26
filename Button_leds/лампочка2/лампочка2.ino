#define btn_pin 3
#define led_pin 9

int val_max = 0;
int val_min = 1024;

void setup() {
  Serial.begin(9600);
  pinMode(btn_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

bool val_last = 1;
bool val = 1;

int count = 0;

void loop() {
  val_last = val;
  val = digitalRead(btn_pin);

  Serial.println(val);
  delay(100);
  if (val == 0 && val_last == 1)
  {
    count++;
  }

  if (count % 2 == 1)
  {
    digitalWrite(led_pin, HIGH);
  }
  else
  {
    digitalWrite(led_pin, LOW);
  }
}