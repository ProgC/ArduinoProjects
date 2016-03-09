void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT); // r 
  pinMode(10,OUTPUT); // g
  pinMode(9,OUTPUT); // b
}

void setColor(int r, int g, int b)
{
  analogWrite(11, r);
  analogWrite(10, g);
  analogWrite(9, b);
}

void loop() 
{
  setColor(255,0,0);    
  delay(3000);
  setColor(0,255,0);    
  delay(3000);
  setColor(0,0,255);    
  delay(3000);
}

