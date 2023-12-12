const int irSensor1 = 4; 
const int irSensor2 = 5;

void setup() {

  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);

  Serial.begin(9600);

}

void loop() {

  bool sensor1Status = digitalRead(irSensor1) < 1;
  bool sensor2Status = digitalRead(irSensor2) < 1;

  if(sensor1Status && sensor2Status){
    Serial.println("Drone Detected!");
  }
  else {
    Serial.println("No drone detected.");
  }

  delay(200);

}
