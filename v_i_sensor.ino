const int voltageSensorPin = A1; 
const int currentSensorPin = A2; 
float voltageValue = 0;
float current_mA = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int voltageSensorValue = analogRead(voltageSensorPin); 
  voltageValue = voltageSensorValue * (5.0 / 1023.0); 
  
  int currentSensorValue = analogRead(currentSensorPin); 
  current_mA = currentSensorValue * (5.0 / 1023.0)*5000; 
  
  Serial.print("Voltage: ");
  Serial.print(voltageValue);
  Serial.println(" V");
  
  Serial.print("Current: ");
  Serial.print(current_mA);
  Serial.println(" mA");
  
  delay(100);
}
