// Define pin yang digunakan
const int pirPin = 2;    // Pin sensor PIR terhubung ke pin digital 2
const int relayPin = 7;  // Pin relay terhubung ke pin digital 3

void setup() {
  pinMode(pirPin, INPUT);    // Set pin sensor PIR sebagai input
  pinMode(relayPin, OUTPUT); // Set pin relay sebagai output
  digitalWrite(relayPin, LOW); // Pastikan relay mati saat mulai
  Serial.begin(9600); // Mulai komunikasi serial dengan kecepatan 9600 bps
}

void loop() {
  int pirState = digitalRead(pirPin); // Baca nilai sensor PIR

  if (pirState == HIGH) { // Jika sensor mendeteksi gerakan
    Serial.println("Gerakan Terdeteksi!"); // Tampilkan pesan di serial monitor
    digitalWrite(relayPin, HIGH); // Nyalakan relay
  } else {
    Serial.println("Tidak ada Gerakan!"); // Tampilkan pesan di serial monitor
    digitalWrite(relayPin, LOW); // Matikan relay
  }
  delay(5000); // Tunggu 5 detik sebelum melakukan pembacaan lagi
}
