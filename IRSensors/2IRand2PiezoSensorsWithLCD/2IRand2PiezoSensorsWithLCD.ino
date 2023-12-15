#include <LiquidCrystal_I2C.h>

// Pin Definitions
const int irSensorPin1 = 4; // IR sensor in '4' pin of Arduino Mega 2560
const int irSensorPin2 = 5; // IR Sensor in '5' pin
const int piezoSensorPin1 = A0; // Piezo Sensor in 'A0' pin
const int piezoSensorPin2 = A1; // Piezo Sensor in 'A1' pin

// Sensor Thresholds
int piezoThreshold = 10; // Threshold for piezo sensors

// LCD Display Setup
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27

void setup() {
  pinMode(irSensorPin1, INPUT);
  pinMode(irSensorPin2, INPUT);
  pinMode(piezoSensorPin1, INPUT);
  pinMode(piezoSensorPin2, INPUT);

  lcd.init(); // Initialize the LCD
  lcd.backlight();
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("System Ready");
}

void loop() {
  // Read 0 value to both IR sesnsors
  bool irStatus1 = digitalRead(irSensorPin1) == 0; 
  bool irStatus2 = digitalRead(irSensorPin2) == 0;
  // Read Piezo Sensors
  int piezoReading1 = analogRead(piezoSensorPin1);
  int piezoReading2 = analogRead(piezoSensorPin2);
  // Conditon of Piezo Sensors
  bool piezoStatus1 = piezoReading1 > piezoThreshold; 
  bool piezoStatus2 = piezoReading2 > piezoThreshold;

  // Check if ALL four sensors are triggered
  if(irStatus1 && irStatus2 && piezoStatus1 && piezoStatus2) {
    Serial.println("Drone detected!");
    lcd.setCursor(0, 1);
    lcd.print("Drone Detected    ");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("No Drone Detected ");
    Serial.println("No Object Detected");
  }

  delay(300); // Adjust this delay as needed
}

