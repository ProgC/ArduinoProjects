// When it receives 48 then we send a signla to 10.
// If user press the reset button then we stop the alarm.
// Kiyoung Moon

#include <Wire.h> // i2c control library
#include <LiquidCrystal_I2C.h> // lcd library

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the lcd

// liquidcrystal_i2c 라이브러리의 write함수의 리턴값을 0이 아닌 1로 수정해주어야 한다.
// 즉, 기존 리턴값은 0인데 이것을 1로 바꾸어 주어야 한다. 아두이노의 소스가 바뀌는 바람에 생겨나는 문제.
//inline size_t LiquidCrystal_I2C::write(uint8_t value) {
//  send(value, Rs);
//  return 1;
//}

void Reset()
{
  lcd.clear();
  lcd.print("Build Error");
  lcd.setCursor(0,1);
  lcd.print("Detecting...");
}

void setup() 
{ 
  lcd.init(); // init lcd

  lcd.backlight(); // turn on backlight
  Reset();
    
  pinMode(10, OUTPUT); // signal for relay or led.
  pinMode(13, INPUT); // reset button
    
  // for serial connection
  Serial.begin(9600);  
}

void loop() 
{
  if ( Serial.available() )
  {
    int data = Serial.read();
    if ( data == 48 )
    {
      lcd.clear();
      lcd.print("Error Found");
      lcd.setCursor(0,1);  
            
      for ( int i = 0; i < 10; ++i )
      {
        lcd.setCursor(0,1);
        lcd.print("... " + (String)i);
        
        // v == 0 means user pressed button.  
        int v = digitalRead(13);
        digitalWrite(10, HIGH);
        delay(1000);
        //if ( v == 0 )
        //{
          // user wants to break.
          //break;
        //}
      }
      
      Reset();
      digitalWrite(10, LOW);
      delay(2000);
    }
  }
}
