int Door_Signal = 12;
int doorClosed = 1;
int Red_Led=11;
int Green_Led=10;

void setup() {
  Serial.begin(9600);                    
  pinMode(Door_Signal, INPUT); 
  pinMode(Red_Led, OUTPUT);
  pinMode(Green_Led, OUTPUT);
}

void loop() {

  if ((digitalRead(Door_Signal) == LOW) )
    {
      Serial.println("DOOR OPEN!!");  
      digitalWrite(Red_Led, HIGH);
      digitalWrite(Green_Led, LOW);

    } 
    else if ((digitalRead(Door_Signal) == HIGH))
    {
      Serial.println("DOOR CLOSED!!");  
      digitalWrite(Red_Led, LOW);
      digitalWrite(Green_Led, HIGH);
    }
    delay(1000);
}
