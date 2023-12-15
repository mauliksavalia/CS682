// pin for sensors
const int irSensorPin = 4; 
const int piezoSensorPin = A0;
// Threshold Values
int piezoThreshold = 100;
int distance = 1;

void setup() {

  // setup pins in Arduino
  pinMode(irSensorPin, INPUT);
  pinMode(piezoSensorPin, INPUT);
  
  Serial.begin(9600);
} 

void loop(){

// condition of Sesnsors
  bool irStatus = digitalRead(irSensorPin) < distance;
  
  int piezoReading = analogRead(piezoSensorPin);

  
  bool piezoStatus = piezoReading > piezoThreshold;

  // Check if BOTH sensors triggered  
  if(irStatus && piezoStatus) {

    Serial.println("Motion detected!");
  
  } else {

    Serial.println("No motion.");
  
  }

  delay(300);

}