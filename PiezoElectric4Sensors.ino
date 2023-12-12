// Piezo sensor pins 
const int piezoPin1 = A0;
const int piezoPin2 = A1; 
const int piezoPin3 = A2;
const int piezoPin4 = A3;

const int threshold = 100;

void setup() {
  Serial.begin(9600);
  
  // Set all pins as input
  pinMode(piezoPin1, INPUT);
  pinMode(piezoPin2, INPUT);
  pinMode(piezoPin3, INPUT);
  pinMode(piezoPin4, INPUT);  
}

void loop() {

  // Read each sensor
  int sensor1 = analogRead(piezoPin1);
  int sensor2 = analogRead(piezoPin2); 
  int sensor3 = analogRead(piezoPin3);
  int sensor4 = analogRead(piezoPin4);

  // Check threshold for each
  bool sensor1Triggered = (sensor1 > threshold);
  bool sensor2Triggered = (sensor2 > threshold);
  bool sensor3Triggered = (sensor3 > threshold);
  bool sensor4Triggered = (sensor4 > threshold);

  // Check if ALL triggered
  if(sensor1Triggered && sensor2Triggered && sensor3Triggered && sensor4Triggered) {
    Serial.println("Motion detected!");
  }
  else {
    Serial.println("No motion.");
  }
  
  delay(500);
}
