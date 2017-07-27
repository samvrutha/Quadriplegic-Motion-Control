//this is master
#include <Adafruit_Sensor.h>
#include <Adafruit_MMA8451.h>
#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

Adafruit_MMA8451 mma = Adafruit_MMA8451();
byte TiltBoi = 0;
int sendinfo;

void setup() 
{
  BTSerial.begin(38400);

  Serial.begin(38400);
  if (! mma.begin()){
    Serial.println("Couldnt start");
    while(1);
  }
  Serial.println("MMA8451 found!");
  mma.setRange(MMA8451_RANGE_2_G);
}

void loop()
{  
  mma.read();
   
  sensors_event_t event; 
  mma.getEvent(&event);
  uint8_t o = mma.getOrientation();


   switch (o) {
    case MMA8451_PL_PUF: 
      Serial.println(" Back ");
      sendinfo = 1;
      break;
    case MMA8451_PL_PDF: 
      Serial.println("Forward ");
      sendinfo = 2;
      break;
    case MMA8451_PL_LRF: 
      Serial.println("Right ");
      sendinfo = 3;
      break;
    case MMA8451_PL_LLF: 
      Serial.println("Left ");
      sendinfo = 4 ;
      break;
    case MMA8451_PL_LLB: 
      Serial.println("Tilt");
      TiltBoi = !TiltBoi;
      Serial.println(TiltBoi);
      break;
    case MMA8451_PL_PUB: 
      Serial.println("Tilt");
      TiltBoi = !TiltBoi;
      Serial.println(TiltBoi);
      break;    
    case MMA8451_PL_PDB: 
      Serial.println("Tilt");
      TiltBoi = !TiltBoi;
      Serial.println(TiltBoi);
      break;
    case MMA8451_PL_LRB: 
      Serial.println("Tilt");
      TiltBoi = !TiltBoi;
      Serial.println(TiltBoi);
      break;
    }
   Serial.println();

   if (TiltBoi){
      BTSerial.write(sendinfo);
   }
   else{
     sendinfo = 5;
     BTSerial.write(sendinfo);  
   }
delay(1000);
}

