
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
BlynkTimer timer;
char auth[] = "50HwVa01BaM9yV1VMF3wI83aEU0eU1eO";
char ssid[] = "SJM";
char pass[] = "Sjm@240988";

#define MQ2 34
#define GREEN 16
#define RED 17
int sensorValue = 0;
boolean state = false;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(MQ2, INPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  timer.setInterval(1000L, sendUptime);
}
void sendUptime()
{
  
  sensorValue = analogRead(MQ2);
  Blynk.virtualWrite(V1, sensorValue);
  Serial.println(sensorValue);

  if (sensorValue > 1500)
  {
    Blynk.notify("Alert!!! GAS Levels Elavated");
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
  }

  else
  {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
}

void loop()
{
  Blynk.run();
  timer.run();
  

}
