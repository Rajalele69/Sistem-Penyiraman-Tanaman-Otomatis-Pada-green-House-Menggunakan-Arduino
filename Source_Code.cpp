// Mendeklarasikan pin untuk sensor kelembapan, relay, dan LED
int sensorPin = A0; // Pin analog untuk sensor kelembapan tanah
int relayPin = 7;   // Pin digital untuk kontrol relay
int ledPin = 13;    // Pin untuk LED indikator (optional)

// Menyimpan nilai kelembapan yang terdeteksi
int moistureLevel = 0;

// Nilai ambang batas kelembapan tanah (misalnya 400 untuk tanah kering)
int moistureThreshold = 400;

void setup() {
  // Inisialisasi pin
  pinMode(relayPin, OUTPUT);   // Menetapkan pin relay sebagai OUTPUT
  pinMode(ledPin, OUTPUT);     // Menetapkan pin LED sebagai OUTPUT
  Serial.begin(9600);          // Memulai komunikasi serial untuk debugging
}

void loop() {
  // Membaca nilai kelembapan tanah dari sensor
  moistureLevel = analogRead(sensorPin);

  // Menampilkan nilai kelembapan di Serial Monitor (untuk debugging)
  Serial.print("Kelembapan Tanah: ");
  Serial.println(moistureLevel);

  // Jika kelembapan tanah lebih rendah dari threshold, aktifkan pompa
  if (moistureLevel < moistureThreshold) {
    digitalWrite(relayPin, HIGH);  // Menyalakan pompa
    digitalWrite(ledPin, HIGH);    // Menyalakan LED (indikator)
    Serial.println("Pompa Air Aktif");
  } else {
    digitalWrite(relayPin, LOW);   // Mematikan pompa
    digitalWrite(ledPin, LOW);     // Mematikan LED
    Serial.println("Tanah Cukup Lembap");
  }

  delay(1000);  // Tunggu 1 detik sebelum membaca ulang
}
