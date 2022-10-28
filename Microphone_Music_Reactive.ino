
#include <Adafruit_NeoPixel.h>

#define LED_PIN  15 

int r = 255; int g = 0; int b = 128;
//int s = 0;

#define NUMPIXELS 8 

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); 
  Serial.begin(9600);
}

void loop() {

  s=analogRead (32);
  Serial.println(s);
  delay(20);

 if((s<=1800))
     { r = 0; g = 0 ; b = 0;}
  
   else if((s>1800)&&(s<=2000))
     { r = 198; g = 0 ; b = 126;}
  
   else if((s>2000)&&(s<=2200))
     {r = 0; g = 255 ; b = 255;}
   
   else if((s>2200)&&(s<=2400))
     {r = 255; g = 180 ; b = 0;}
  
   else if((s>2400)&&(s<=2600))
     {r = 0; g = 255 ; b = 0;}
   
   else if((s>2600)&&(s<=2800))
     {r = 0; g = 0 ; b = 255; }
   
   else if((s>2800)&&(s<=3000))
     {r = 0; g = 128 ; b = 255;}
   
   else  
      {r = 255; g = 0 ; b = 0;}


  for(int i=0; i<4; i++) { 
    
   pixels.setPixelColor(4+i, pixels.Color(r, g, b));
   pixels.setPixelColor(3-i, pixels.Color(r, g, b));
    delay(25);
    pixels.show(); 
  }

}
