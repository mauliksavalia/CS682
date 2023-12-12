
#include <LiquidCrystal_I2C.h>
const int irSensor = 4;

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27

void setup() {
pinMode(irSensor, INPUT);
lcd.init(); // initialize the lcd
lcd.backlight();
Serial.begin(9600);
}

void loop() {
int irValue = digitalRead(irSensor);
if(irValue < 1){
Serial.println("Object Detected");
lcd.setCursor(0, 1);
lcd.print("Drone Detected");
}
else{
lcd.setCursor(0, 1);
lcd.print("No Drone Detected!");
Serial.println("No Object Detected");
}

delay(300);
}