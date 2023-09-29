#include <Servo.h>
#include <HCSR04.h>

#define servo_pin 2
#define echo_pin 3
#define trig_pin 4

//inicia o servo
Servo servo;
//inicia o sensor de distancia
HCSR04 hcsr04(trig_pin, echo_pin);

void setup() {
  Serial.begin(9600);
  servo.attach(servo_pin);
  servo.write(0); 
}

void loop() {
  float distance = hcsr04.dist();

  Serial.println(distance);

  //se a distancia for menor que 20cm durante 500ms, abre a lixeira por 10 segundos depois fecha
  if(distance < 20.0){
    delay(500);
    distance = hcsr04.dist();
    Serial.println(distance);
    if(distance < 20.0){
      servo.write(90);
      delay(10000);
      servo.write(0);
    }
  }
  delay(200);
}
