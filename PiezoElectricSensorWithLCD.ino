#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensorPin = A0; // Pin connected to piezo sensor
const int threshold = 10; // Threshold value to detect press

void setup() {
  Serial.begin(9600); // Initialize serial 
  pinMode(sensorPin, INPUT);
  lcd.init(); // Initialize LCD
  lcd.backlight();
  lcd.print("Piezo Sensor:"); // Set pin as input
}

void loop() {

  int sensorValue = analogRead(sensorPin); // Read analog voltage

  // Check if pressure is applied
  if(sensorValue > threshold){
    Serial.println("Pressure detected!");
    while(analogRead(sensorPin) > threshold){
    lcd.setCursor(0, 1);

    lcd.print("Drone Detected!"); 
    }
  }

  else{
    Serial.println("Not in a range!");
    lcd.setCursor(0, 1);
    lcd.print("Not in a Range!!!!!");
}
  
  delay(200); // Small delay
}

