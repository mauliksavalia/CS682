const int volDetPin = A0;
float vin;
float vout;
float voltageDetVal;
const float shldredfactor = 5.128;
const float vcc = 5.00;


void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltageDetVal = analogRead(volDetPin);
  vout = (voltageDetVal/1024)*vcc;
  vin = vout*shldredfactor;

  Serial.print("Voltage = ");
  Serial.print(vin);
  Serial.println("V");

  delay(1000);


}
