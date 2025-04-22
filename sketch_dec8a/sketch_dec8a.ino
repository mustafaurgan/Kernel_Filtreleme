const int trigPin = 2;  // Trig pinini bağladığınız dijital pin
const int echoPin = 3;  // Echo pinini bağladığınız dijital pin
unsigned long previousMillis = 0;  // Önceki ölçüm zamanı
const long interval = 5000;  // 5 saniyelik ölçüm aralığı
long measurements[60];  // 5 dakika boyunca 60 ölçüm alacak bir dizi
int index = 0;  // Ölçüm dizisinin indeksi

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

  // Şu anki zamanı al
  unsigned long currentMillis = millis();

  // Belirlenen aralıkta bir ölçüm al
  if (currentMillis - previousMillis >= interval) {
    // Önceki ölçüm zamanını güncelle
    previousMillis = currentMillis;

    // Ölçümü ölçüm dizisine ekle
    measurements[index] = distance;

    // İndeks artırılır
    index++;

    // 5 dakika boyunca 60 ölçüm alındıysa, verileri işle ve sıfırla
    if (index == 60) {
      // Ölçümleri işleme fonksiyonunu çağır
      processMeasurements();

      // İndeksi sıfırla
      index = 0;
    }
  }

  // 100 milisaniye bekleme
  delay(100);
}

// 5 dakika boyunca alınan ölçümleri işleyen fonksiyon
void processMeasurements() {
  Serial.println("---- 5 Dakika Sonu ----");
  Serial.println("Ortalama Mesafeler:");

  // Toplam mesafeyi hesapla
  long totalDistance = 0;
  for (int i = 0; i < 60; i++) {
    totalDistance += measurements[i];
  }

  // Ortalamayı bul
  int averageDistance = totalDistance / 60;

  // Ortalamayı seri monitöre yazdır
  Serial.print("Ortalama Mesafe: ");
  Serial.print(averageDistance);
  Serial.println(" cm");
}
