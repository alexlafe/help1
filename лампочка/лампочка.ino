#define sensor_pin A2
#define led_pin 3

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  int val = analogRead(sensor_pin);
  Serial.println(val);
  delay(10);

  if (val < 900) 
  {
    digitalWrite(led_pin, HIGH); 
  }
  else 
  {
    digitalWrite(led_pin, LOW);   
  }
}