const int voltageSensorPin = A0; 
const int currentSensorPin = A1; 
void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int voltageValue = analogRead(voltageSensorPin);
  float voltage = voltageValue * (5.0 / 1023.0);  
  int currentSensorValue = analogRead(currentSensorPin);
  Serial.print("Voltage (V): ");
  Serial.println(voltage);
  Serial.print("Current (A): ");
  Serial.println(current);  
  
  delay(1000); 
}
