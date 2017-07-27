#include <ZumoMotors.h>

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1);


ZumoMotors motors;
int Back = 1;
int Forward = 2;
int Right = 3;
int Left = 4;
int Off = 5; 
int val;

void setup() {
  BTSerial.begin(38400);
  Serial.begin(9600);
  motors.setRightSpeed(0);
  motors.setLeftSpeed(0);
  BTSerial.listen();
   
  if(BTSerial.available() > 0 ){ 
     val = BTSerial.read();  
  }
}

void loop() {
    while (Back == val){
      for (int speed = 0; speed >= -400; speed--){
          motors.setRightSpeed(speed);
          motors.setLeftSpeed(speed);        
       }
       if(BTSerial.available() > 0){
        val =  BTSerial.read();
       }   
    }
    
    while (Forward == val){
      for (int speed = 0; speed <= 400; speed++){
          motors.setRightSpeed(speed);
          motors.setLeftSpeed(speed);          
       }
       if(BTSerial.available() > 0){
        val =  BTSerial.read();
       }  
    }
    
     while (Left == val){
       for (int speed = 0; speed <= 400; speed++){
          motors.setRightSpeed(speed);
          motors.setLeftSpeed(0);                 
       }
       if(BTSerial.available() > 0){
        val =  BTSerial.read();
       } 
    }
    
     while (Right == val){
       for (int speed = 0; speed <= 400; speed++){
          motors.setLeftSpeed(speed);
          motors.setRightSpeed(0);          
       }
       if(BTSerial.available() > 0){
        val =  BTSerial.read();
       }
     }
     
     while (Off == val){
      for (int speed = 0; speed <= 400; speed++){
       motors.setLeftSpeed(0);
       motors.setRightSpeed(0); 
      }  
       if(BTSerial.available() > 0){
          val =  BTSerial.read();
       }  
     }
      if(BTSerial.available() > 0){
        val =  BTSerial.read();
      }

     motors.setRightSpeed(0);
     motors.setLeftSpeed(0);
}

