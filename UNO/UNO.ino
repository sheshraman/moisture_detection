#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "sdfgsdgjkhdfgkndfsgjkldf"; // the auth code that you got on your gmail
char ssid[] = "Harsh Home"; // username or ssid of your WI-FI
char pass[] = "ngfbasketball"; // password of your Wi-Fi
int water ;
int prevState = 0;


void setup()
{
  Serial.begin(9600);
  pinMode (D3,OUTPUT);
  pinMode (D5,INPUT);
  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{ 
  Blynk.run();

 water=digitalRead(D5);
 Serial.println(water);

  if (water == HIGH && prevState == 0) 
  {
  Serial.println("Pump Started, Water Flowing");    
  digitalWrite(D3,LOW);
  Blynk.notify("Pump Started, Water Flowing");
  prevState = 1;
  delay(400);    
  }     
  
  else if (water == HIGH && prevState == 1)
  {
  Serial.println("Pump Stopped, Water Not Flowing"); 
  delay(400);
  }
  else 
  { 
  digitalWrite(D3,HIGH);
  prevState =0;
  }
  
  
  delay(100);
}
