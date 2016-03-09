void setup() 
{
  Serial.begin(9600);
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
}

void loop() 
{
 // digitalWrite(13,HIGH);
  int sw = digitalRead(13);
  Serial.println(sw);

  if ( sw == LOW )
  {
    //digitalWrite(2, HIGH);
    int tones[] = { 349, 392, 349, 294, 294, 261, 230 };
    for ( int i = 0; i < 7; ++i )
    {
      tone(2, tones[i]);
      delay(150);
    }
  }  
  else
  {
    //digitalWrite(2, LOW);
    //tone(2, 0);
    noTone(2);
    delay(200);
  }
  delay(300);
}
