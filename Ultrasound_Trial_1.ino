
const int TrigPin = 25;
const int EchoPin = 26;

float duration;
float distance_cm;

void setup() {

  // Open the communication channel between computer and microcontroller
  Serial.begin (115200);
   
   // set up Trig pin as an OUTPUT (Emitter)
  pinMode(TrigPin, OUTPUT);

  // set up the Echo pin to INPUT (receiver)
  pinMode(EchoPin, INPUT);
 
}

void loop() {
  // generate 10-microsecond pulse to Trig pin.  Remember a microsecond is one millionth of a second.
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration = pulseIn(EchoPin, HIGH);

  // calculate the distance.  0.017 is the speed of sound in microseconds divided by two duration will record the time there and back)
  distance_cm = duration * 0.017;

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // add in a short delay so we can see the difference before it changes
  delay(300);
}
