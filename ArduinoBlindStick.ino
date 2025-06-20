// defines pins numbers
const int trigPin = 9; // HC-SR04 Trig Pin Defination
const int echoPin = 10; // HC-SR04 Echo Pin Defination
const int buzzer = 11; // Buzzer Pin Defination
const int ledPin = 13; // Led Pin Defination

// defines variables
long duration; // Time Variable
int distance; // Distance read by sensor
int safetyDistance; // Safety Distance if distance less than safetyDistance then buzzer and led goes off


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT); // Sets Buzzer as output
pinMode(ledPin, OUTPUT); // Sets LED as output
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;

// Distance and Buzzer Logic
if (safetyDistance <= 25){ 
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}