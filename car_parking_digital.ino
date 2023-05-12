#include <ThingSpeak.h>               // add librery
#include <ESP8266WiFi.h>

WiFiClient  client;
unsigned long counterChannelNumber = 1679836;                // Channel ID
const char * myCounterReadAPIKey = "VEENEJGTOW1SQEOR";      // Read API Key
const char * myCounterWriteAPIKey = "CT1R15GRU13F9M6M";     // Write API Key

const int ir1= 5;
const int ir2= 4;
const int ir3= 0;
const int ir4= 2;
const int ir5= 14;
const int ir6= 12;
 

void setup()
{
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  pinMode(ir4,INPUT);
  pinMode(ir5,INPUT);
  pinMode(ir6,INPUT);
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("Area-51", "Sherlocked");                 // write wifi name & password           

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() 
{
digitalWrite(ir1, HIGH); 
digitalWrite(ir2, HIGH); 
digitalWrite(ir3, HIGH);
digitalWrite(ir4, HIGH);
digitalWrite(ir5, HIGH);
digitalWrite(ir6, HIGH);

  
  if (digitalRead(ir1)== LOW){   
    ThingSpeak.setField(1,1);                                    // if values are reverse then HIGH change to LOW
    Serial.println(digitalRead(ir1));
    Serial.println("Parked1");
    }
    else{
    ThingSpeak.setField(1,0);
    }

  if (digitalRead(ir2)== LOW){
    ThingSpeak.setField(2,1);
    Serial.println(digitalRead(ir2));
    Serial.println("Parked2");
    }
    else{
    ThingSpeak.setField(2,0);
    }
  if (digitalRead(ir3)== LOW){
    ThingSpeak.setField(3,1);
    Serial.println("Parked3");
    }
    else{
    ThingSpeak.setField(3,0);
    }
  if (digitalRead(ir4)== LOW){
    ThingSpeak.setField(4,1);
    Serial.println("Parked4");
    }
    else{
    ThingSpeak.setField(4,0);
    }
  if (digitalRead(ir5)== LOW){
    ThingSpeak.setField(5,1);
    Serial.println("Parked5");
    }
    else{
    ThingSpeak.setField(5,0);
    }
  if (digitalRead(ir6)== LOW){
    ThingSpeak.setField(6,1);
    Serial.println("Parked6");
    }
    else{
    ThingSpeak.setField(6,0);
    }
  ThingSpeak.writeFields(counterChannelNumber , myCounterWriteAPIKey);

}
