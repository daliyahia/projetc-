#include <SoftwareSerial.h>
#include <string.h>

SoftwareSerial mySerial(7, 8);
String number;

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  Serial.println("GSM SIM900A BEGIN");
  Serial.println();
   mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial();
  delay(100);
}

void loop()
{
  if (Serial.available() > 0) {
    delay(100); // Add a delay to ensure complete input
    number = Serial.readStringUntil('\n');
    number.trim(); // Remove leading and trailing whitespaces
    if (number.length() == 8 ) {
      mySerial.println("ATD+216" + number + ";");
      Serial.println("Calling " + number);
      delay(2000);
    }
  }

  
  updateSerial();
 /* if (mySerial.available() > 0) 
  {
    Serial.write(mySerial.read());
  }*/
}

void updateSerial()
{

  if (Serial.available()>0) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  if(mySerial.available()>0) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
