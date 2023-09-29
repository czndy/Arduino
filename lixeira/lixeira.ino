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

  //se a distancia for menor que 20cm , abre a lixeira por x segundos depois fecha
  if(distance < 20.0){
    distance = hcsr04.dist();
    Serial.println(distance);
    //verifica se já tiraram a mão da frente do sensor para abrir a tampa
    do{
      Serial.println("entrou no DO");
      distance = hcsr04.dist();
      Serial.println(distance);
      if(distance > 20.0){
        delay(500);
        servo.write(90);
        delay(5000);
        //verifica se o usuário continua com a mão na frente do sensor para manter a tampa aberta
        do{
          distance = hcsr04.dist();
          if(distance > 20.0){
            delay(750);
            servo.write(0);
          }else{
            Serial.println("Mantendo tampa aberta");
          }
        }while(distance < 20.0);
      }
    }while(distance < 20.0);
      
  }
  delay(200);
}
