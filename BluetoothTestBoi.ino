/* This is a simple test for two way traffic via bluetooth 
   but you can try it first using the USB cable to the serial 
   monitor without the bluetooth module connected.
   
   Note that some bluetooth modules come set to a different baud rate.
   This means you need to alter the command
                Serial.begin(9600) accordingly
   Same goes for the setting in the bottom right corner on the 
   serial monitor */ 
String readString;
char c;
int led = 13;

void setup()
{
    pinMode(0, INPUT_PULLUP);// only needed for  JY-MCUY v1.06?
    pinMode(led, OUTPUT); 
    Serial.begin(9600);
    Serial.println("OK then, you first, say something.....");
    Serial.println("Go on, type something in the space above");
    Serial.println(" and hit Send or Enter,");
    Serial.println("then I will repeat it!");
    Serial.println("");
}

void loop() {
    while (Serial.available()) 
  {
    delay(3);  
    c = Serial.read();
    readString += c; 
  }// end while
  if (readString.length() >0) 
  {  
    Serial.write(c);  
   readString="";  
  } // end if
}
