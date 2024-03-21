const int ldrPin = A0; // Pin sensor LDR terhubung ke pin analog A0
const int relayPin = 7; // Pin relay terhubung ke pin digital 7

// Konstanta untuk konversi nilai analog menjadi Lux
const float m = 100.0 / 1023.0; // Konstanta gradien
const int offset = 200; // Nilai offset untuk kalibrasi

void setup() {
  Serial.begin(9600); // Mulai komunikasi serial dengan kecepatan 9600 bps
  pinMode(relayPin, OUTPUT); // Set pin relay sebagai output
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Baca nilai sensor LDR

  // Kalibrasi nilai sensor LDR dengan mengurangkan offset
  int calibratedValue = ldrValue - offset;

  // Konversi nilai analog yang telah dikalibrasi menjadi Lux
  float luxValue = calibratedValue * m; // Konversi ke flux

  // Pastikan nilai Lux tidak negatif
  if (luxValue < 0) {
    luxValue = 0;
  }

  // Tampilkan nilai sensor LDR yang telah dikalibrasi dan Lux di serial monitor
  Serial.print("Nilai LDR (Kalibrasi): ");
  Serial.print(calibratedValue);
  Serial.print(" | Lux: ");
  Serial.println(luxValue, 1); // Menampilkan Lux dengan 1 digit setelah koma

  // Kontrol relay berdasarkan nilai Lux
  if (luxValue > 18) {
    digitalWrite(relayPin, HIGH); // Aktifkan relay jika Lux lebih dari 18
  } else {
    digitalWrite(relayPin, LOW); // Matikan relay jika Lux kurang dari atau sama dengan 18
  }

  delay(1000); // Tunggu 1 detik sebelum melakukan pembacaan lagi
}
