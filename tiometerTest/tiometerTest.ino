void setup() {
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{  
  int data = analogRead(A0);
  Serial.println(data);  

  float f = data / 1024.f;  
  analogWrite(11, (int)(f*255));
}
