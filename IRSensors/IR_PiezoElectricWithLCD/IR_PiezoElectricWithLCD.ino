#include <LiquidCrystal_I2C.h>

// Pin Definitions
const int irSensorPin = 4;
const int piezoSensorPin = A0;

// Sensor Thresholds
int piezoThreshold = 10; 

// LCD Display Setup
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(piezoSensorPin, INPUT);

  lcd.init(); // Initialize the LCD
  lcd.backlight();
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("System Ready");
}

void loop() {
  static bool lastIrStatus = false;
  static bool lastPiezoStatus = false;

  // Read sensors
  bool irStatus = digitalRead(irSensorPin) == 0;
  int piezoReading = analogRead(piezoSensorPin);
  //set condition for Sensors
  bool piezoStatus = piezoReading > piezoThreshold;

  // Check if BOTH sensors are triggered
  if(irStatus && piezoStatus) {
    if(!lastIrStatus || !lastPiezoStatus) {
      Serial.println("Motion detected!");
      lcd.setCursor(0, 1);
      lcd.print("Drone Detected    ");
    }
  } else {
    if(lastIrStatus || lastPiezoStatus) {
      lcd.setCursor(0, 1);
      lcd.print("No Drone Detected ");
      Serial.println("No Object Detected");
    }
  }

  // Update the last status
  lastIrStatus = irStatus;
  lastPiezoStatus = piezoStatus;

  delay(300); // Adjust this delay as needed
}
