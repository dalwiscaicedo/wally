#include<Servo.h>
#include <SoftwareSerial.h>
#define pinBase 12
#define pinDer 11
#define pinIzq 10
#define pinMano 9


Servo MotorBase;
Servo MotorDer;
Servo MotorIzq;
Servo MotorMano;


char servo;
int B={(90)}, D{(90)}, I{(90)}, M{(90)};
int ang;

void setup() {
 Serial.begin (9600);
  MotorMano.attach(9);
  MotorBase.attach(12);
  MotorIzq.attach(10);
  MotorDer.attach(11);
  delay (15);
}

void loop() {
  MotorBase.write(B);
  MotorDer.write(D);
  MotorIzq.write(I);
  MotorMano.write(M);
  i();

  switch(servo){
    case'B':
    B=ang;
    break;
    
    case'D':
    D=ang;
    break;   
    
    case'I':
    I=ang;
    break;

    case'M':
    M=ang;
    break;
  };
}

  void i (){
    if (Serial.available() > 0){
      if (Serial.available() <180){
        servo= Serial.read();
        ang= Serial.parseInt ();
      }
    }  
  }
