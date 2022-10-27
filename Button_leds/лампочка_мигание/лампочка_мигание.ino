#define btn_pin 2
#define led_pin 9

void setup() {
  Serial.begin(9600);
  pinMode(btn_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

bool val = 1;
bool val_pr = 1;

int count = 0;

int bright = 0;
bool check_bright = 0;

void loop() 
{
  val_pr = val;
  val = digitalRead(btn_pin);

  if (bright == 254)
  {
    check_bright = 1;
  }
  else if (bright == 0)
  {
    check_bright = 0;
  }
  
  if (val == 0 && val_pr == 0 && bright < 255 && check_bright == 0)
  {
    bright++;
  }
  else if (val == 0 && val_pr == 0 && bright >= 0 && check_bright == 1)
  {
    bright--;
  }

  if (val == 0 && val_pr == 1)
  {
    count++;
  }

  if (count % 2 == 1)
  {
    analogWrite(led_pin, bright);
  }
  else
  {
    analogWrite(led_pin, 0);
  }

  delay(10);
}