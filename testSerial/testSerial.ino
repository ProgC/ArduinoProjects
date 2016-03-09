void setup()
{
  //pinMode(13, OUTPUT);

// 시리얼 통신
  Serial.begin(9600);
}

void loop()
{
  /*digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);*/

  if ( Serial.available() )
  {
    Serial.println(Serial.read());
  }
}

