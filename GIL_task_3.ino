//   GIL task number 3.
   /*here in this task i am performing the OR gate operation using relay module to control a led by two push buttons. the led will remain off if  both push buttons are LOW (0).
   if single switch or both switch are on then led remains ON (1). and show the ON/ OFF condition on LCD screen.*/
    #include <Wire.h>
    #include <LiquidCrystal_I2C.h>
    // I2c module make it easy to use it. no more wiring connections
    LiquidCrystal_I2C lcd(0x27,20,4); // (0x27(adress) , 20(columns), 4(rows) )
    
    int led_pin = 7;// using a relay module to controll the led
    int sw1 = 6; // button 1
    int sw2 = 5; // button 2
    void setup()
    {
    lcd.init();// same command as like lcd.begin()
    pinMode(7, OUTPUT);
    pinMode(6, INPUT);
    pinMode(5, INPUT);
    }
    
    void loop()
    {
      
      lcd.backlight(); // back light of i2c module will glow
      digitalWrite(7, LOW);
      int val_1 = digitalRead(6);
      int val_2 = digitalRead(5);
      // applying conditions
      if (val_1 == HIGH && val_2 == HIGH)// or operation (1,1)
      {
      lcd.setCursor(0,0); // starting from first column and 1st row
      lcd.print("both switchs_ON"); // 
      digitalWrite(7,HIGH);
      delay(100000); // the led will glow for 1 minute
      digitalWrite(3, LOW);
      lcd.clear();
       }
       else if(val_1 ==  HIGH && val_2 == LOW)// (1,0)
       {
//       led remains ON untill both switch become OF and lcd will display switch off.
        lcd.setCursor(2,1); // 2nd column and 2nd row.
        lcd.print("switch 1 on");
        digitalWrite(7, HIGH);
        delay(100000);
        digitalWrite(7, LOW);
        lcd.clear();
        }
        else if(val_1 == LOW && val_2 == HIGH) // (0,1)
       {
//        led remains ON untill both switch become oFF.
        lcd.setCursor(2,2); // 2nd column and 3rd row.
        lcd.print("switch 2 is ON");
        digitalWrite(7, HIGH);
        delay(100000);// timer set to one minute 
        digitalWrite(7, LOW);  
        lcd.clear();
        }
        else if(val_1 == LOW && val_2 == LOW)// (0,0)
       {
        //led remains off untill one or both  switch become on. 
        lcd.setCursor(2,3); // 2nd column and 4th row.
        lcd.print("both switchs of");
        digitalWrite(7, LOW);
        lcd.clear();
        }   
        }
