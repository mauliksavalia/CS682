#include <LiquidCrystal_I2C.h>

const int volDetPin = A0;
float vin;
float vout;
float voltageDetVal;
const float shldredfactor = 5.128;
const float vcc = 5.00;

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27

void setup() {
  lcd.init(); // initialize the LCD
  lcd.backlight();
  lcd.print("Voltage:");
  Serial.begin(9600);
}

void loop() {
  voltageDetVal = analogRead(volDetPin);
  vout = (voltageDetVal / 1024) * vcc;
  vin = vout * shldredfactor;

  Serial.print("Voltage = ");
  Serial.print(vin);
  Serial.println("V");

  lcd.setCursor(0, 1);
  lcd.print("Voltage: ");
  lcd.print(vin);
  lcd.print("V");

  delay(1000);
}