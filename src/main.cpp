#include <Arduino.h>

// put function declarations here:
#define soilmoistPin A1
int dry = 294;
int wet = 670;
int SoilValue;
const int relayPin = 7;
void setup()
{
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
}
void soilCount()
{ 
  int soilmoist = analogRead(soilmoistPin);
  int soilMoistPercent = map(soilmoist, wet, dry, 0, 100);
  soilMoistPercent = constrain(soilMoistPercent, 0, 100);
  Serial.print("Soil Moisture: ");
  Serial.print(soilMoistPercent);
  // SoilValue = soilMoistPercent;
  Serial.println("%");
  delay(1000);
}

void relayDC(){
  if(SoilValue < 50){
    digitalWrite(relayPin, HIGH);
  }
  else{
    digitalWrite(relayPin, LOW);
  }
}

void loop()
{
  soilCount();
}
