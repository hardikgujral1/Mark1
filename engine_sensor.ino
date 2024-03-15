#define LEFT_SENSOR_PIN 2  
#define RIGHT_SENSOR_PIN 3 
#define INDICATOR_PIN 4    
#define LEFT_PISTON_PIN 5  
#define RIGHT_PISTON_PIN 6 
#define BLACK_THRESHOLD 200
#define POTENTIOMETER_PIN A0

const int voltageSensorPin = A1; 
const int currentSensorPin = A2; 
float voltageValue = 0;
float current_mA = 0;

int threshold = 0;

void setup() {
  pinMode(LEFT_SENSOR_PIN, INPUT);
  pinMode(RIGHT_SENSOR_PIN, INPUT);
  pinMode(INDICATOR_PIN, OUTPUT);
  pinMode(LEFT_PISTON_PIN, OUTPUT);
  pinMode(RIGHT_PISTON_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leftSensorValue = analogRead(LEFT_SENSOR_PIN);
  int rightSensorValue = analogRead(RIGHT_SENSOR_PIN);
  threshold = map(analogRead(POTENTIOMETER_PIN), 0, 1023, 0, 1000);

  // Read voltage sensor
  int voltageSensorValue = analogRead(voltageSensorPin); 
  voltageValue = voltageSensorValue * (5.0 / 1023.0); 
  
  // Read current sensor
  int currentSensorValue = analogRead(currentSensorPin); 
  current_mA = currentSensorValue * (5.0 / 1023.0) * 5000; 
  
  Serial.print("Voltage: ");
  Serial.print(voltageValue);
  Serial.println(" V");
  
  Serial.print("Current: ");
  Serial.print(current_mA);
  Serial.println(" mA");
  
  // Control left piston
  if (leftSensorValue < BLACK_THRESHOLD) {
    digitalWrite(LEFT_PISTON_PIN, HIGH); // Energize left NPN Transistor
  } else {
    digitalWrite(LEFT_PISTON_PIN, LOW); // De-energize
  }

  // Control right piston
  if (rightSensorValue < BLACK_THRESHOLD) {
    digitalWrite(RIGHT_PISTON_PIN, HIGH); // Energize right NPN Transistor
  } else {
    digitalWrite(RIGHT_PISTON_PIN, LOW); // De-energize 
  }

  // Control indicator pin
  if (leftSensorValue < BLACK_THRESHOLD || rightSensorValue < BLACK_THRESHOLD) {
    digitalWrite(INDICATOR_PIN, HIGH); // INDICATOR PIN
  } else {
    digitalWrite(INDICATOR_PIN, LOW); // OFF INDIACATOR PIN
  }
  
  delay(threshold);
}
