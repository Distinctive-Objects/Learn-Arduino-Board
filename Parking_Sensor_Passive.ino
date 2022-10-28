
uint8_t octave = 6;

const int TrigPin = 25;
const int EchoPin = 26;

int timer;

float duration;
float distance_cm;

void setup() {
  
  Serial.begin (115200);
  
   ledcSetup(0, 1E5, 12);
   ledcAttachPin(15, 0); // Change 25 to 26 as required
  
   pinMode(TrigPin, OUTPUT);
    pinMode(EchoPin, INPUT);
 
 }

void loop() {
 
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  
  duration = pulseIn(EchoPin, HIGH);

  distance_cm = duration * 0.017;

  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  ledcWriteNote(0, NOTE_E, octave);
  delay(50);
  ledcWrite(0, 0); 

  if (distance_cm > 300) {
        distance_cm == 30; 
        }

  else {
      timer = distance_cm * 10;
      }

delay(timer);

}
