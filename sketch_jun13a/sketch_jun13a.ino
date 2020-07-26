
int LEDPin01 = 9;
int LEDPin02 = 3;
int waitTimeOn = 500;
int waitTimeOff = 500;
int totalBlinks = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(LEDPin01,OUTPUT);
  pinMode(LEDPin02,OUTPUT);

  
}

void loop()
{
  
  
  for(int i=0; i < 5; i++)
  {
    
    
    digitalWrite(LEDPin01,HIGH);
    digitalWrite(LEDPin02,LOW);
    totalBlinks += 1;
    Serial.print("   Blink #: ");
    Serial.println(totalBlinks);
    delay(waitTimeOn);

    digitalWrite(LEDPin01,LOW);
    digitalWrite(LEDPin02,HIGH);
    totalBlinks += 1;
    Serial.print("   Blink #: ");
    Serial.println(totalBlinks);
    delay(waitTimeOff);
  
  }
  Serial.println("Holding for 2 seconds...");
  digitalWrite(LEDPin01,HIGH);
  digitalWrite(LEDPin02,HIGH);
  delay(2000);
}
