const int irSensor1 = 4; // Connect IR sensor 1 to pin 1
int x;

void setup() {
  pinMode(irSensor1, INPUT); 
  // pinMode(irSensor2, INPUT);
  Serial.begin(9600);
}

void loop() {

  x = digitalRead(irSensor1);
  if(x < 1){
    Serial.println("Drone Detected!");
  }
  else{
    Serial.println("Not in a Range!");
  }

  delay(200);
}
