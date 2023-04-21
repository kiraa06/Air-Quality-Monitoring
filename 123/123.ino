#include <LiquidCrystal.h>
#include <MQ135.h>
#include <LiquidCrystal.h>
#include<dht.h>

dht DHT11;

#define DHT11_PIN A1


int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

 void setup()
 {
      Serial.begin(9600);
      analogWrite(6,Contrast);
      lcd.begin(16, 2);
      
  } 
     void loop()
 {
     int sensorValue = analogRead(A0);

     Serial.print("AirQuality=");
     Serial.print(sensorValue, DEC);
     Serial.println(" PPM");

     int chk = DHT11.read11(DHT11_PIN);
     Serial.print(" Humidity " );
     Serial.print(DHT11.humidity, 1);
      Serial.print(" ");
      Serial.print(" Temparature ");
     Serial.println(DHT11.temperature, 1);
   
     lcd.setCursor(0, 0);
     lcd.print("Air Quality :");
     lcd.print(sensorValue, DEC);
    
   
     lcd.setCursor(0, 1);
     lcd.print("T :");
     lcd.print(DHT11.temperature, 1);
     lcd.print(" H :");
     lcd.print(DHT11.humidity, 1);

     delay(2000);
 }
