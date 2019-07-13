#include <Servo.h>
 #include <SoftwareSerial.h>
Servo servoM;
Servo servoI;
Servo servoD;
Servo servoB;

int B={80}, D={20}, I={120}, M={80};
 char dato;

void setup()
{
  servoM.attach(9);
  servoI.attach(10);
  servoD.attach(11);
  servoB.attach(12);

   
   
    servoM.write(M);
  servoI.write(I);
  servoD.write(D);
 servoB.write(B);

  
 Serial.begin(9600); 
delay(15);


  
}
 
void loop()
{

      if (Serial.available() > 0){
      if (Serial.available() <180){
        dato= Serial.read();
        

  if(dato=='B'){
        servoM.write(M);
        M++;
     }
     else if(dato=='A'){
        servoM.write(M);
       M--;
     }
      else if(dato=='F'){
      servoI.write(I);
    I++;
     }
     else if(dato=='E'){
      servoI.write(I);
     I--;
     }
    else if(dato=='C'){
        servoD.write(D);
        D++;
     }
     else if(dato=='D'){
        servoD.write(D);
        D--;
     }
     else if(dato=='G'){
        servoB.write(B);
        B++;
     }
     else if(dato=='H'){
        servoB.write(B);
        B--;
     }
       if(dato=='S'){
      
      servoB.attach(12);  
      servoB.write (80);  
 delay (100);

 
  servoI.attach(10);  
  servoI.write (120);  
 delay (100);
 

  servoD.attach(11);  
  servoD.write (20);  
 delay (100);


  servoM.attach(9);  
  servoM.write (80);  
 delay (100);

 

for(I;I!=132;I++){
  servoI.write(I);
  delay(20);
  }
  
for(D;D!=75;D++){
  servoD.write(D);
  delay(20);
  }
  
for(M;M!=90;M++){
  servoM.write(M);
  delay(20);
  }
for(D;D!=0;D--){
  servoD.write(D);
  delay(20);
  }
for(B;B!=180;B++){
 servoB.write(B);
  delay(20);
  }
for(I;I!=145;I++){
  servoI.write(I);
  delay(20);
  }
for(M;M!=40;M--){
    servoM.write(M);
  delay(20);
} 
      servoB.attach(12);  
      servoB.write (80);  
 delay (100);

}
 

     
    }
     }
     
}
