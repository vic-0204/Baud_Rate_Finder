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

## ⚡ Configuration

You may need to adjust the following values depending on your hardware setup:

```cpp
#define PIN_RX 10       // The pin of your board that will be used for measurement
const int numTransitions = 8;  // Number of signal edges to sample for measurement
```
1. PIN_RX → Which pin of your measuring board you want to use for capturing the signal (connect it to the TX of the device you want to measure).
2. numTransitions → Increasing this number may improve accuracy.

## ⚠️ Important Note

For the baud rate to be measured correctly,  
the device you want to analyze **must be actively transmitting data**.  

If the device is idle (not sending anything), the tool will not detect the baud rate.  
In this case, you need to make sure the device starts transmitting data (e.g., trigger a command, enable logging, or connect it to a system that requests data).  

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
```cpp
baud = 1 000 000 / min_delta
```

5. Standard Matching – The calculated baud is mapped to the closest known rate.
6. Output – The detected baud rate is printed to Serial Monitor.

---

## ☕ Support My Work

If you enjoy my projects and want to support me, you can do so through the links below:

[![Buy Me A Coffee](https://img.shields.io/badge/-Buy%20Me%20a%20Coffee-FFDD00?style=for-the-badge&logo=buy-me-a-coffee&logoColor=black)](https://www.buymeacoffee.com/muki01)
[![PayPal](https://img.shields.io/badge/-PayPal-00457C?style=for-the-badge&logo=paypal&logoColor=white)](https://www.paypal.com/donate/?hosted_button_id=SAAH5GHAH6T72)
[![GitHub Sponsors](https://img.shields.io/badge/-Sponsor%20Me%20on%20GitHub-181717?style=for-the-badge&logo=github)](https://github.com/sponsors/muki01)

📧 **Contact:** `muksin.muksin04@gmail.com`

---
