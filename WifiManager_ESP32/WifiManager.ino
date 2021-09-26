
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLOaZZIidk"
#define BLYNK_DEVICE_NAME "WifiManager"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

#define LEDPIN 2

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7

#include "BlynkEdgent.h" 

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V1);  // will cause BLYNK_WRITE(V1) to be executed
  Blynk.syncVirtual(V0);  // will Blynk.virtualWrite(V0, millis()/value) to be executed
}

BLYNK_WRITE(V1) // Executes when the value of virtual pin 1 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(LEDPIN,HIGH);  // Set digital LEDPIN HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(LEDPIN,LOW);  // Set digital LEDPIN LOW    
  }

}


void setup()
{
  Serial.begin(115200);
  delay(100);

  pinMode(LEDPIN, OUTPUT); // Initialise digital pin 2 as an output pin

  
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
