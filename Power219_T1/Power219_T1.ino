#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

  float current_mA = 0;
  float power_mW = 0;
  float energy_Wh=0;
  long time_s=0;

void setup(void) 
{
  Serial.begin(9600);
  uint32_t currentFrequency;
  ina219.begin();
  Serial.println("Measuring voltage and current with INA219");
}

void loop(void) 
{
  getData();
  delay(2000);
}

void getData(){
  
 time_s=millis()/(1000); // convert time to sec
 current_mA = ina219.getCurrent_mA();
 //power_mW = ina219.getPower_mW(); 
 power_mW=current_mA*voltage_V; 
 energy_Wh=(power_mW*time_s)/3600;   //energy in watt hour
   
  

  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");  
  Serial.print("Energy:        "); Serial.print(energy_Wh); Serial.println(" mWh");
  Serial.println("----------------------------------------------------------------------------");
}
