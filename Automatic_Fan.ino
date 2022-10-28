
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode (18,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(14);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(10);        // delay in between reads for stability


  if (sensorValue > 1750) {
    digitalWrite (18,HIGH);
  }

  else {
    digitalWrite (18,LOW);
  }
}
