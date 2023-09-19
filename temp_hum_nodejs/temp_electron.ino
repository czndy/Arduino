#include <DHT.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11
DHT dht(DHT_PIN,DHT_TYPE);

//the code here will be executed only once. Here we are initializing the Serial and the DHT sensor.
void setup() {
  Serial.begin(9600);
  dht.begin();
}

//the code here will be executed in a loop. The delay function sets the time interval that this loop will be executed.
void loop() {
  
  //here we are organizing the reading of the sensor data into two separate variables.
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.print(temp, 1);
  // Serial.print((char)223); // "°" symbol
  Serial.println(" C");
  Serial.print("Humidity: ");
  Serial.print(hum, 1);
  Serial.println("%");
  Serial.println("###############");

  delay(1000);
  
}
