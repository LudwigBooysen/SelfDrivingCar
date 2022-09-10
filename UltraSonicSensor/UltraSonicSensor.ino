
// USS = Ultra Sonic Sensor

// Declare Pins Variables
int trigPin = 8; // Trigger Pin on USS
int echoPin = 9; // Echo Pin on USS
int distance; // Calculated value from USS

void setup() {
  // Assign Pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {
  // Send Signals with trigger pins on USS
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Calculate distance from recieved info from echo pin on USS
  // Distance is in cm (metric)
  distanc e= pulseIn(echoPin, HIGH)*0.034/2;
  
  // Make trun chooice with distance
  // Pin 2 is the relay for dc motors
  if (distance < 50) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}
