//Mahadev Sharma
//Mahadev Sharma
//Mood lighting with Punch Through LightBlue Bean
#include <Adafruit_NeoPixel.h>
// The pin that is connected to the NeoPixels
#define PIN 5
// The amount of LEDs in the NeoPixels
#define NUMPIXELS 16
// LedReading is the type we get when we call Bean.getLedValues();
// For example, to get the amount of red in the Bean's LED,
// we use ledColor.red to get a value from 0 to 255
LedReading ledColor;
// previousLedColor will be used to check if the LED's color has changed
LedReading previousLedColor;
// Set up the NeoPixel library
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();  //  Initialize the NeoPixels
  Bean.enableWakeOnConnect(true);
}

void loop() {
  if(Bean.getConnectionState()) {
    ledColor = Bean.getLed();
    if(ledColor.red != previousLedColor.red ||
      ledColor.green != previousLedColor.green ||
      ledColor.blue != previousLedColor.blue) {
      for(int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(
          i, pixels.Color(ledColor.red, ledColor.green, ledColor.blue));
        pixels.show();
      }
    previousLedColor = ledColor;
    }
  }
  else {
    Bean.sleep(0xFFFFFFF);
  }
}