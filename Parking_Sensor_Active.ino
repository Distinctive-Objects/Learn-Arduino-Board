
const int TrigPin = 25;
const int EchoPin = 26;
const int BuzzerPin = 15;

int timer;

float duration;
float distance_cm;

void setup() {
  
  Serial.begin (115200);
  
   pinMode(TrigPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(BuzzerPin,OUTPUT);
 
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

  digitalWrite(BuzzerPin,HIGH);
  delay(50);
  digitalWrite(BuzzerPin,LOW);

  if (distance_cm > 300) {
        distance_cm == 30; 
        }

  else {
      timer = distance_cm * 10;
      }

delay(timer);
}
