#define TRIG_PIN 2
#define ECHO_PIN 3

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

int getDistance() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  while (digitalRead(ECHO_PIN) == LOW);
  long startTime = micros();
  while (digitalRead(ECHO_PIN) == HIGH);
  long travelTime = micros() - startTime;

  float distance = travelTime / 58.0;
  int distanceInt = (int)distance;

  return distanceInt;
}

void loop() {
  int distances[60];

  for (int i = 0; i < 60; ++i) {
    distances[i] = getDistance();
    Serial.print(distances[i]);
    Serial.print("cm\n ");
    delay(4990);
  }

  Serial.println("\nMeasurement complete!");
  while (1) {
  }
}
