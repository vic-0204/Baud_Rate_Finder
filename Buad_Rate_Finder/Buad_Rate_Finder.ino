#define PIN_RX 10     // RX pin
#define PIN_TX 11     // TX pin (if needed)
#define RX_BUFFER 32  // Data buffer size

const int numTransitions = 8;
float measuredBaud = 9600;  // Default, measured

void setup() {
  Serial.begin(115200);  // For monitor logging
  pinMode(PIN_RX, INPUT);

  Serial.println("Measuring Baud Rate...");
  measuredBaud = measureBaud();
  measuredBaud = measureBaud();

  // RX = PIN_RX, TX = PIN_TX
  Serial1.begin(measuredBaud, SERIAL_8N1, PIN_RX, PIN_TX);
}

void loop() {
  // Read incoming UART data
  while (Serial1.available()) {
    uint8_t b = Serial1.read();
    Serial.print("0x");
    if (b < 0x10) Serial.print("0");  // 0 for single digit
    Serial.print(b, HEX);
    Serial.print(" ");
  }

  delay(50);  // Slight delay to avoid flooding
}

// Measure baud rate based on edge transitions
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

if (baud > 150 && baud < 450) {
    newBaud = 300;
} else if (baud > 450 && baud < 700) {
    newBaud = 600;
} else if (baud > 700 && baud < 900) {
    newBaud = 750;
} else if (baud > 900 && baud < 1800) {
    newBaud = 1200;
} else if (baud > 1800 && baud < 3000) {
    newBaud = 2400;
} else if (baud > 4000 && baud < 5600) {
    newBaud = 4800;
} else if (baud > 9200 && baud < 10000) {
    newBaud = 9600;
} else if (baud > 10000 && baud < 10800) {
    newBaud = 10400;
} else if (baud > 18400 && baud < 20000) {
    newBaud = 19200;
} else if (baud > 28000 && baud < 35000) {
    newBaud = 31250;
} else if (baud > 36000 && baud < 40000) {
    newBaud = 38400;
} else if (baud > 50000 && baud < 62000) {
    newBaud = 57600;
} else if (baud > 70000 && baud < 80000) {
    newBaud = 74880;
} else if (baud > 100000 && baud < 125000) {
    newBaud = 115200;
} else if (baud > 200000 && baud < 240000) {
    newBaud = 230400;
} else if (baud > 240000 && baud < 260000) {
    newBaud = 250000;
} else if (baud > 400000 && baud < 480000) {
    newBaud = 460800;
} else if (baud > 480000 && baud < 520000) {
    newBaud = 500000;
} else if (baud > 900000 && baud < 1100000) {
    newBaud = 1000000;
} else {
    newBaud = baud; // Unrecognized, use measured
}

  Serial.print("Estimated baud: ");
  Serial.print(baud, 0);
  Serial.print(" Baud  ");
  Serial.print("Set: ");
  Serial.println(newBaud);

  return newBaud;
}
