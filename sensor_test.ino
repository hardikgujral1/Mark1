#define LEFT_SENSOR_PIN 2   
#define RIGHT_SENSOR_PIN 3   
#define INDICATOR_LED_PIN 7  

#define BLACK_THRESHOLD 200

void setup() {
  pinMode(LEFT_SENSOR_PIN, INPUT);
  pinMode(RIGHT_SENSOR_PIN, INPUT);
  pinMode(INDICATOR_LED_PIN, OUTPUT);
}

void loop() {
  int leftSensorValue = analogRead(LEFT_SENSOR_PIN);
  int rightSensorValue = analogRead(RIGHT_SENSOR_PIN);

  // Check Postion 
  if (leftSensorValue < BLACK_THRESHOLD || rightSensorValue < BLACK_THRESHOLD) {
    digitalWrite(INDICATOR_LED_PIN, HIGH); 
  } else {
    digitalWrite(INDICATOR_LED_PIN, LOW);  
  }
}
