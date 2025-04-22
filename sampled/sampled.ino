const int trigPin = 2;      // Trig pinini bağladığınız dijital pin
const int echoPin = 3;      // Echo pinini bağladığınız dijital pin
const int sampleRate = 5000; // Örnekleme hızı (5 saniyede bir)
const int numSamples = 600;  // Toplam örnek sayısı (5 dakika / 5 saniye)

long duration;
int distance;
int samples[numSamples];

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

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58;

  // Elde edilen mesafeyi seri monitörde gösterme
  Serial.println(distance);

  // Örnekleme hızına göre sinyali saklama
  static int sampleCounter = 0;
  if (sampleCounter < numSamples) {
    samples[sampleCounter] = distance;
    sampleCounter++;
  }

  // Belirli bir süre boyunca sinyali örnekle
  if (sampleCounter == numSamples) {
    // Düşük geçiren filtre uygula
    lowPassFilter(samples);

    // Yüksek geçiren filtre uygula
    highPassFilter(samples);

    // Örnekleme işlemini sıfırla
    sampleCounter = 0;
  }

  delay(sampleRate);  // Belirli bir süre boyunca bekletme
}

void lowPassFilter(int *data) {
  // Düşük geçiren filtre algoritması buraya eklenebilir
  // Örnek olarak, hareketli ortalama filtresi kullanılabilir
}

void highPassFilter(int *data) {
  // Yüksek geçiren filtre algoritması buraya eklenebilir
  // Örnek olarak, verinin ortalamasını çıkararak yüksek frekans bileşenleri alabilirsiniz
}
