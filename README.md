# Baud Rate Finder

![GitHub forks](https://img.shields.io/github/forks/muki01/Baud_Rate_Finder?style=flat)
![GitHub Repo stars](https://img.shields.io/github/stars/muki01/Baud_Rate_Finder?style=flat)
![GitHub Issues or Pull Requests](https://img.shields.io/github/issues/muki01/Baud_Rate_Finder?style=flat)
![GitHub License](https://img.shields.io/github/license/muki01/Baud_Rate_Finder?style=flat)
![GitHub last commit](https://img.shields.io/github/last-commit/muki01/Baud_Rate_Finder)

A cross-platform utility (Arduino, ESP32, ESP8266…) to automatically measure and detect the baud rate of unknown serial devices.

---

## 📌 Description

**Baud_Rate_Finder** uses edge timing on the RX pin to estimate the baud rate of an incoming serial signal.  
Instead of guessing or testing multiple rates, this sketch compares measured timings against common baud rates and outputs the closest match.

✅ Works on **Arduino**, **ESP32**, **ESP8266**, and other boards that support `micros()` and digital I/O.

---

## ⚙️ Features

- Detects baud rate automatically from a connected serial device  
- Multi-platform support (Arduino, ESP32, ESP8266, etc.)  
- Supports **standard baud rates**:  
  **300, 600, 750, 1200, 2400, 4800, 9600, 10400, 19200, 31250, 38400, 57600, 74880, 115200, 230400, 250000, 460800, 500000, 1000000**  
- Prints results to Serial Monitor  

---

## 🛠️ Installation

1. Download the repository.
2. Open Baud_Rate_Finder.ino in Arduino IDE.
3. Upload to your Arduino board.
4. Connect your serial device and open the Serial Monitor to see the detected baud rate.

## 📝 Usage Example
```cpp
void loop() {
  int baud = measureBaud();
  Serial.print("Estimated Baud Rate: ");
  Serial.println(baud);
}
```
Sample output:
```cpp
Measuring Baud Rate...
Estimated Baud Rate: 115200
```

## 📊 How it Works
1. Signal Sampling – The RX pin is monitored for a fixed number of edges.
2. Timestamping – Each transition is recorded with micros().
3. Bit Duration – The smallest interval (min_delta) is treated as the bit time.
4. Baud Calculation – Estimated using:
```
baud = 1,000,000 / min_delta
```

5. Standard Matching – The calculated baud is mapped to the closest known rate.
6. Output – The detected baud rate is printed to Serial Monitor.
