// IR sensor pins
const int irSensor1 = 2;
const int irSensor2 = 3; 
const int irSensor3 = 4;
const int irSensor4 = 5;
float distance = 1;

void setup() {

  // Set all sensor pins as input
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);
  pinMode(irSensor4, INPUT);

  Serial.begin(9600); 
}

void loop() {

  // Read each sensors
  bool sensor1State = digitalRead(irSensor1) < distance;
  bool sensor2State = digitalRead(irSensor2) < distance;
  bool sensor3State = digitalRead(irSensor3) < distance;
  bool sensor4State = digitalRead(irSensor4) < distance;

  // if all 4 IR sesnors are triggered simultenously 
  if(sensor1State && sensor2State && sensor3State && sensor4State){
    Serial.println("Object detected by all sensors!");
  }
  else{
    Serial.println("No object detected.");
  }

  delay(300); // required delay
}
