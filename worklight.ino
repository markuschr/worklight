//#include <ESP8266WiFi.h>  
//#include <WiFiClient.h>  
//#include <ThingSpeak.h>  
const int fetPin = D3;
const int ledPin = D1;
const int threshold = 820;                // corresponding value for 10.8 Volts
const int uppthreshold = 830;             // threshold for the low battery indication LED
const int numReadings = 4;                // size of the sensorValue array to be averaged
int sensorValue[numReadings];             // the readings from the analog input
int readIndex = 0;                        // the index of the current reading
int total = 0;                            // the running total
int average = 0;                          // the average
int inputPin = A0;
bool calc_batt_level = false;             // After numReadings measurements, the average is correct and we can determine the batterylevel.
int batterylevel = 0;                     // three levels for the battery: 0 if < 10.8 V, 1 if < 11.0 V and 2 if > 11.0 V  
int delaytime = 100;                      // milliseconds, when uploading values to thingspeak minimum delay time is 15000
//const char* ssid = "your wifi";                // enter wifi ssid
//const char* password = "your wifi password";   // enter wifi password
//WiFiClient client;  
//unsigned long myChannelNumber = 1234567;         // your thingspeak channel number       
//const char * myWriteAPIKey = "I0X92XXX32XXXX20"; // your thingspeak write API key

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(fetPin, OUTPUT);
   // Connect to WiFi network  
  //Serial.println();  
  //Serial.println();  
  //Serial.print("Connecting to ");  
  //Serial.println(ssid);  
  //WiFi.begin(ssid, password);  
  //while (WiFi.status() != WL_CONNECTED)  
  {  
   //delay(500);  
   //Serial.print(".");  
  }  
  //Serial.println("");  
  //Serial.println("WiFi connected");  
  // Print the IP address  
  //Serial.println(WiFi.localIP());  
  //ThingSpeak.begin(client);
}

void loop() {
      
    total = total - sensorValue[readIndex];        // subtract the last reading:
    sensorValue[readIndex] = analogRead(inputPin); // read from the sensor:
    total = total + sensorValue[readIndex];        // add the reading to the total:
    readIndex = readIndex + 1;                     // advance to the next position in the array:

    if (readIndex >= numReadings) {   // if we're at the end of the array...
      readIndex = 0;                  // ...wrap around to the beginning:
      calc_batt_level = true;         // average is now correct and we get the right batterylevel
      delaytime = 15000;              // delay can be increased after the first 4 values have been read
    }

    average = total / numReadings;    // calculate the average:
    if (average <= uppthreshold){
      batterylevel = 1;
      if (average <= threshold) {
        batterylevel = 0;
      }
    }  
    if (average > uppthreshold) {
      batterylevel = 2;
    }

    if (calc_batt_level) {    // do something different depending on the batterylevel:
       
       switch (batterylevel) {
         case 2:    // voltage over 10.8 V
           digitalWrite(fetPin, HIGH); // circuit for the COB LED is ON
           digitalWrite(ledPin, LOW); // low battery LED is OFF
           break;
         case 1:    // battery close to 10.8 V
           digitalWrite(fetPin, HIGH); // circuit for the COB LED is ON
           digitalWrite(ledPin, HIGH); // low battery LED is ON
           break;
         case 0:    // battery too close to 10.8 V
           digitalWrite(fetPin, LOW); //circuit for the COB LED is OFF
           digitalWrite(ledPin, LOW); // low battery LED is ON
           break;     
       }
    }
    //ThingSpeak.writeField(myChannelNumber, 1, average, myWriteAPIKey);  // write to thingspeak channel field 1 
    delay(delaytime);
  }
  
