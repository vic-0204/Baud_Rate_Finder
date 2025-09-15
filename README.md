# Baud_Rate_Finder

![GitHub forks](https://img.shields.io/github/forks/muki01/Baud_Rate_Finder?style=flat)
![GitHub Repo stars](https://img.shields.io/github/stars/muki01/Baud_Rate_Finder?style=flat)
![GitHub Issues or Pull Requests](https://img.shields.io/github/issues/muki01/Baud_Rate_Finder?style=flat)
![GitHub License](https://img.shields.io/github/license/muki01/Baud_Rate_Finder?style=flat)
![GitHub last commit](https://img.shields.io/github/last-commit/muki01/Baud_Rate_Finder)

Detect and measure the baud rate of serial devices automatically using Arduino.

---

## 📌 Description

**Baud_Rate_Finder** is an Arduino project that allows you to quickly determine the baud rate of any connected serial device. Instead of manually guessing or trying multiple baud rates, this tool automatically detects the closest standard baud rate, including both common and rare rates.

**Supported Baud Rates:**  
300, 600, 750, 1200, 2400, 4800, 9600, 10400, 19200, 31250, 38400, 57600, 74880, 115200, 230400, 250000, 460800, 500000, 1000000  

---

## ⚙️ Features

- Automatically detects baud rate of any serial device  
- Supports both standard and uncommon baud rates  
- Easy-to-use Arduino sketch  
- Lightweight and fast  

---

## 🛠️ Installation

1. Download the repository.
2. Open Baud_Rate_Finder.ino in Arduino IDE.
3. Upload to your Arduino board.
4. Connect your serial device and open the Serial Monitor to see the detected baud rate.

## 📊 How it Works
The Baud_Rate_Finder sketch works by measuring the timing of incoming serial signals on the RX pin and estimating the baud rate based on edge transitions.
