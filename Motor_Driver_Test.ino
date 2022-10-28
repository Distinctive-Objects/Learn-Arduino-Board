/*
 Motor driver Test
  Turns an the motor on for one second in one direction, then off for one second, then on in the other direction, off, then repeat.
  
modified from blink by Distinctive Objects 2021

*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins 4 and 5 as outputs.
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(4, HIGH);   // Switch outpin pin 4 to HIGH.  This makes Input 1 on the motor driver HIGH, spinning the motor in one direction.
  digitalWrite(5, LOW);   // Switch outpin pin 5 to LOW.  This makes Input 2 on the motor driver LOW. For the motor to spin only one Input pin on the motor driver can be high.
  delay(1000);                       // wait for a second
  digitalWrite(4, LOW);    // turn the Motor off by making the voltage  at Input 1 LOW
  delay(1000);                       // wait for a second
  digitalWrite(5, HIGH);   // Switch outpin pin 4 to HIGH.  This makes Input 2 on the motor driver HIGH, spinning the motor in one direction.
  delay(1000);
  digitalWrite(5, LOW);   // Switch outpin pin 4 to HIGH.  This makes Input 2 on the motor driver high, spinning the motor in one direction.
  delay(1000);
  // sketch now cycles back to the start
}
