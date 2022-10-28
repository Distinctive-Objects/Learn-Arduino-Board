
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//int sensorValue = 0; not needed as we're showing Tc
int ThermistorPin = 14;

float Vout;
float R1 = 10000;
float R2;
float Tk;
float Tc;
float A = 0.001065308552122;
float B = 0.000234711863267;
float C = 0.000000085663516;
  
void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 connection failed"));
    for(;;);
  }
}

void loop() {
  
 //sensorValue = analogRead(14); we are doing this in the next line

 Vout = analogRead(ThermistorPin);
  R2 = R1 * (4096.0 / Vout - 1.0);
  Tk = (1.0 / (A + B*log(R2) + C*pow(log(R2),3) ));
  Tc = Tk - 273.15;


  delay(200);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  
  // Display our data by bringing in our factors into the display.print
  display.println("Temperature: ");
  
  display.setCursor(13, 20);
  display.setTextSize(3);
  display.print (Tc);
  display.println("C ");
  
  display.display(); 
  delay(500);
  
}
