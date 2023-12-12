const int piezoPin1 = A0; 
const int piezoPin2 = A1;

const int threshold = 50; 

void setup() {
  Serial.begin(9600);

  pinMode(piezoPin1, INPUT);
  pinMode(piezoPin2, INPUT);
}

void loop() {

  int sensor1Value = analogRead(piezoPin1);
  int sensor2Value = analogRead(piezoPin2);


  bool sensor1Triggered = (sensor1Value > threshold);
  delay(100); 
  bool sensor2Triggered = (sensor2Value > threshold);

  
  if(sensor1Triggered && sensor2Triggered) {
    Serial.println("Motion detected!");
  }



}