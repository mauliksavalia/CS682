const int sensorPin = A0; // Pin connected to piezo sensor
const int threshold = 10; // Threshold value to detect press

void setup() {
  Serial.begin(9600); // Initialize serial 
  pinMode(sensorPin, INPUT); // Set pin as input
}

void loop() {

  int sensorValue = analogRead(sensorPin); // Read analog voltage

  // Check if pressure is applied
  if(sensorValue > threshold){ 
    Serial.println("Pressure detected!");
  }
  
  delay(10); // Small delay
}
