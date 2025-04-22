const int trigPin = 2;  // Trig pinini bağladığınız dijital pin
const int echoPin = 3;  // Echo pinini bağladığınız dijital pin

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Mesafe ölçümü
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration / 58;

  // Mesafeyi seri monitöre yazdırma
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);  // 1 saniye bekleme
}
