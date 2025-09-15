#define PIN_RX 10     // RX pini
#define PIN_TX 11     // TX pini (gerekirse)
#define RX_BUFFER 32  // Okunacak veri miktarı

const int numTransitions = 8;

float measuredBaud = 9600;  // Varsayılan, ölçülür

void setup() {
  Serial.begin(115200);  // Monitöre log için
  pinMode(PIN_RX, INPUT);

  Serial.println("Baud rate ölçülüyor...");
  measuredBaud = measureBaud();
  measuredBaud = measureBaud();

  // RX = PIN_RX, TX = PIN_TX
  Serial1.begin(measuredBaud, SERIAL_8N1, PIN_RX, PIN_TX);
}

void loop() {
  // Gelen UART verisini oku
  while (Serial1.available()) {
    uint8_t b = Serial1.read();
    Serial.print("0x");
    if (b < 0x10) Serial.print("0");  // Tek basamaklıysa başına sıfır
    Serial.print(b, HEX);
    Serial.print(" ");
  }

  delay(50);  // Hafif bekleme
}

// Kenar değişimlerine göre baud hesapla
int measureBaud() {
  unsigned long timestamps[numTransitions];
  int count = 0;
  int last_state = digitalRead(PIN_RX);

  while (count < numTransitions) {
    int current = digitalRead(PIN_RX);
    if (current != last_state) {
      timestamps[count++] = micros();
      last_state = current;
    }
  }

  unsigned long min_delta = 0xFFFFFFFF;
  for (int i = 1; i < numTransitions; i++) {
    unsigned long delta = timestamps[i] - timestamps[i - 1];
    if (delta > 0 && delta < min_delta) {
      min_delta = delta;
    }
  }

  int baud = 1000000.0 / min_delta;
  int newBaud = 0;

  if (baud > 9200 && baud < 1000) {
    newBaud = 9600;
  } else if (baud > 10000 && baud < 10800) {
    newBaud = 10400;
  } else if (baud > 4400 && baud < 5200) {
    newBaud = 4800;
  } else if (baud > 18600 && baud < 19800) {
    newBaud = 19200;
  } else if (baud > 100000 && baud < 150000) {
    newBaud = 115200;
  } else {
    newBaud = baud;  // Bilinmeyen baud → ölçülmüş değeri kullan
  }

  Serial.print("Tahmini baud: ");
  Serial.print(baud, 0);
  Serial.print(" baud  ");
  Serial.print("Set: ");
  Serial.println(newBaud);

  return newBaud;
}
