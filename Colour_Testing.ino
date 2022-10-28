#include <Adafruit_NeoPixel.h>

#define PIN 15

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);
int SoundLevel = 0;
float SoundLevelFilter = 0;
int RGBmap = 0;

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop() {
    SoundLevel = analogRead(32);
    Serial.println (SoundLevel);

   if (SoundLevel <1750)  { 
      strip.setPixelColor(1, strip.Color(0,153,0));
    }
   

   if (SoundLevel >1750 & SoundLevel<1968) { 
      strip.setPixelColor(1, strip.Color(0,153,0));
      strip.setPixelColor(2, strip.Color(051,204,0));
    }
   
   if (SoundLevel >1968 & SoundLevel <2186) {
    strip.setPixelColor(1, strip.Color(0,153,0));
    strip.setPixelColor(2, strip.Color(051,204,0));
    strip.setPixelColor(3, strip.Color(102,255,051));
    }

     if (SoundLevel >2186 & SoundLevel <2400) {
    strip.setPixelColor(1, strip.Color(0,153,0));
    strip.setPixelColor(2, strip.Color(051,204,0));
    strip.setPixelColor(3, strip.Color(102,255,051));
    strip.setPixelColor(4, strip.Color(204,255,000));
    }

    if (SoundLevel >2400 & SoundLevel <2680) {
     strip.setPixelColor(1, strip.Color(0,153,0));
    strip.setPixelColor(2, strip.Color(051,204,0));
    strip.setPixelColor(3, strip.Color(102,255,051));
    strip.setPixelColor(4, strip.Color(204,255,000));
    strip.setPixelColor(5, strip.Color(255,255,051));
    }

    if (SoundLevel >2680 &  SoundLevel <2910)  {
      strip.setPixelColor(1, strip.Color(0,153,0));
    strip.setPixelColor(2, strip.Color(051,204,0));
    strip.setPixelColor(3, strip.Color(102,255,051));
    strip.setPixelColor(4, strip.Color(204,255,000));
    strip.setPixelColor(5, strip.Color(255,255,051));
    strip.setPixelColor(6, strip.Color(255,204,051));
    }

    if (SoundLevel >2910 &  SoundLevel<3400)  {
      strip.setPixelColor(1, strip.Color(0,153,0));
    strip.setPixelColor(2, strip.Color(051,204,0));
    strip.setPixelColor(3, strip.Color(102,255,051));
    strip.setPixelColor(4, strip.Color(204,255,000));
    strip.setPixelColor(5, strip.Color(255,255,051));
    strip.setPixelColor(6, strip.Color(255,204,051));
    strip.setPixelColor(7, strip.Color(255,102,000));
    }

     if (SoundLevel>3400) {
      strip.setPixelColor(1, strip.Color(0,153,0));
    strip.setPixelColor(2, strip.Color(051,204,0));
    strip.setPixelColor(3, strip.Color(102,255,051));
    strip.setPixelColor(4, strip.Color(204,255,000));
    strip.setPixelColor(5, strip.Color(255,255,051));
    strip.setPixelColor(6, strip.Color(255,204,051));
    strip.setPixelColor(7, strip.Color(255,102,000));
    strip.setPixelColor(8, strip.Color(255,000,000));
    }
 

  
  strip.show();
  delay (5);
 for (int i = 1; i < strip.numPixels(); i++) {
     strip.setPixelColor(i, strip.Color(0, 0, 0));
 strip.show();
 delay (5);
 }
   }
