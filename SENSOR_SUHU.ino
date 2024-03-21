#include <DHT.h>
#define DHTPIN 2     // Pin data DHT22 terhubung ke pin digital 2 pada Arduino Nano
#define DHTTYPE DHT22   // Tipe sensor DHT (DHT11, DHT21, DHT22)

DHT dht(DHTPIN, DHTTYPE);
const int relayPin = 8; // Pin relay terhubung ke pin digital 3 pada Arduino Nano
const float suhuAmbang = 25.0; // Ambang suhu untuk mengaktifkan relay

void setup() {
  Serial.begin(9600); // Mulai komunikasi serial dengan kecepatan 9600 bps
  dht.begin(); // Mulai sensor DHT
  pinMode(relayPin, OUTPUT); // Set pin relay sebagai output
}

void loop() {
  delay(2000); // Tunggu 2 detik antara pembacaan

  // Baca suhu (dalam Celcius) dari sensor DHT
  float temperature = dht.readTemperature();
  // Baca kelembaban (dalam persen) dari sensor DHT
  float humidity = dht.readHumidity();

  // Cek jika membaca suhu atau kelembaban gagal
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Gagal membaca dari sensor DHT");
    return;
  }

  // Tampilkan suhu dan kelembaban di serial monitor
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.print(" °C | Kelembaban: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Mengaktifkan relay jika suhu mencapai ambang batas
  if (temperature >= suhuAmbang) {
    digitalWrite(relayPin, HIGH); // Nyalakan relay
    Serial.println("Relay ON"); // Tampilkan pesan di serial monitor
  } else {
    digitalWrite(relayPin, LOW); // Matikan relay
    Serial.println("Relay OFF"); // Tampilkan pesan di serial monitor
  }
}
