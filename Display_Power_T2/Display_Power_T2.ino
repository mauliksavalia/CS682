#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_INA219.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27

Adafruit_INA219 ina219;
float current_mA = 0;
float power_mW = 0;
float energy_Wh = 0;
long time_s = 0;
float voltage_V = 0.0; // Voltage connected to INA219

void setup(void) {
  Wire.begin(); // Initialize I2C
  lcd.init(); // Initialize the LCD
  lcd.backlight();
  // lcd.print("Power & Voltage:");
  Serial.begin(9600);

  ina219.begin();
  Serial.println("Measuring voltage and current with INA219");
  voltage_V = ina219.getBusVoltage_V(); // Get the initial voltage value
}

void loop(void) {
  getData();
  delay(2000);
}

void getData() {
  time_s = millis() / 1000; // Convert time to seconds
  current_mA = ina219.getCurrent_mA();
  power_mW = current_mA * voltage_V;
  energy_Wh = (power_mW * time_s) / 3600; // Energy in watt-hours

  Serial.print("Current:");
  Serial.print(current_mA);
  Serial.println(" mA");
  Serial.print("Power:         ");
  Serial.print(power_mW);
  Serial.println(" mW");
  Serial.print("Energy:        ");
  Serial.print(energy_Wh);
  Serial.println(" mWh");
  Serial.println("----------------------------------------------------------------------------");

  lcd.setCursor(0, 0);
  lcd.print("Current:");
  lcd.print(current_mA);
  lcd.print("mA     Power:");
  lcd.print(power_mW);
  lcd.print(" mW");

  lcd.setCursor(0, 1);
  lcd.print("Energy:");
  lcd.print(energy_Wh);
  lcd.print(" mWh");
}