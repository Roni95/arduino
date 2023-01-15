int buzzer = 12;//8;
int LED_red = 3;//7;
int LED_green =4;
int flame_sensor = 13;//4;
int flame_detected;
int gas=0;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT); // MQ-6 A0 Pin
  pinMode(buzzer, OUTPUT);
  pinMode(LED_red, OUTPUT);
  pinMode(flame_sensor, INPUT);
}
void loop()
{
  flame_detected = digitalRead(flame_sensor);
  gas = analogRead(A0);
  Serial.println(flame_detected);
  Serial.println(gas);
  if ((flame_detected == 1) || (gas >= 500))
  {
    Serial.println("Fire or Gas detected...! take action immediately.");
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED_red, HIGH);
    digitalWrite(LED_green, LOW);
    delay(200);
  }
  else
  {
    Serial.println("No fire and gas detected. stay cool");
    digitalWrite(buzzer, LOW);
    digitalWrite(LED_red, LOW);
    digitalWrite(LED_green, HIGH);
  }
  delay(1000);
}

