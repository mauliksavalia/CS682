const int irSensor1 = 4; // input for IR sensor
int x;

void setup() {
  pinMode(irSensor1, INPUT); 
  Serial.begin(9600);
}

void loop() {

// Read sensor
  x = digitalRead(irSensor1);
  if(x < 1){
    Serial.println("Drone Detected!");
  }
  else{
    Serial.println("Not in a Range!");
  }

  delay(200);
}
