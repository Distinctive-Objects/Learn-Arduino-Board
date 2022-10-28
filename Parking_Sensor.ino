
const int TrigPin = 25;
const int EchoPin = 26;

int timer;

uint8_t octave = 6;

float duration;
float distance_cm;

void setup() {

  // Open the communication channel between computer and microcontroller
  Serial.begin (115200);
  
   ledcSetup(0, 1E5, 12);
   ledcAttachPin(15, 0); // Change 25 to 26 as required
  
   // set up Trig pin as an OUTPUT (Emitter)
  pinMode(TrigPin, OUTPUT);

  // set up the Echo pin to INPUT (receiver)
  pinMode(EchoPin, INPUT);
 
}

void loop() {
  // generate 10-microsecond pulse to Trig pin.  
  //Remember a microsecond is one millionth of a second.
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration = pulseIn(EchoPin, HIGH);

  // calculate the distance.  0.017 is the speed of sound in microseconds/2 
  // the division is necessary as 'duration' will record the time there and back)
  distance_cm = duration * 0.017;

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // add in a short delay so we can see the difference before it changes
//  delay(300);

ledcWriteNote(0, NOTE_E, octave);
delay(50);
//digitalWrite(buzzer, HIGH);
//delay(50);
ledcWrite(0, 0); 
//digitalWrite(buzzer, LOW);


if (distance_cm > 300) {distance_cm == 30; }

else {timer = distance_cm * 10;}

delay(timer);

  
}
