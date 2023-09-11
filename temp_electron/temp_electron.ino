#include <DHT.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11
DHT dht(DHT_PIN,DHT_TYPE);



void setup() {
  Serial.begin(9600);
  dht.begin();

  // pinMode(5, OUTPUT);
  // pinMode(6, OUTPUT);
  // pinMode(7, OUTPUT);

}

void loop() {
  
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.print(temp, 1);
  // Serial.print((char)223);
  Serial.println(" C");
  Serial.print("Humidity: ");
  Serial.print(hum, 1);
  Serial.println("%");
  Serial.println("###############");

  // if(temp >= 30){
  //   digitalWrite(5, LOW);
  //   digitalWrite(6, LOW);
  //   digitalWrite(7, HIGH);
  // }else if(temp >= 22){
  //   digitalWrite(5, LOW);
  //   digitalWrite(6, HIGH);
  //   digitalWrite(7, LOW);
  // }else{
  //   digitalWrite(5, HIGH);
  //   digitalWrite(6, LOW);
  //   digitalWrite(7, LOW);
  // }

  delay(1000);
  
}
