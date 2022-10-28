
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
}

void loop() {

  Vout = analogRead(ThermistorPin);
  R2 = R1 * (4096.0 / Vout - 1.0);
  Tk = (1.0 / (A + B*log(R2) + C*pow(log(R2),3) ));
  Tc = Tk - 273.15;

  Serial.print("Temperature: "); 
  Serial.print(Tc);
  Serial.println(" C");   

  delay(500);
}
