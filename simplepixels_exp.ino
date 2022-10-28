#include <Adafruit_NeoPixel.h>

#define PIN        15 

#define NUMPIXELS 8 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

//#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels

void setup() {

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  
  
  
  for(int i=4; i<4; i++) {
    pixels.setPixelColor(i, pixels.Color(Colour)

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(10); // Pause before next pass through loop
  }
}
