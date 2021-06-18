# DASH POS ESP32

Ongoing project with functionality to notify payments received in DASH.

[![DASH POS ESP32](https://img.youtube.com/vi/npzFl3ya2Bg/0.jpg)](https://www.youtube.com/watch?v=npzFl3ya2Bg)

## Getting Started
This section should help you get started with the project. If you have any questions feel free to open an issue.

### Prerequisites
- ESP32
- Nextion 3.5"
- Buzzer 3.3v

### Installing/Setting

Edit file: `main.cpp`
```c++
const char* ssid = ""; //Enter SSID
const char* password = ""; //Enter Password
```

Edit file: `screen_header.h`
```c++
const int SPEAKER = 32; // PIN BUZZER
String TOKEN_QRCODE = "Xipy6LQYz8ELjtqGr9YEaZU5spid8K8tjx"; // You DASH Address
```

## Change Log
- **18/06/2021 (v0.1.1)** - Initial commits and support for ESP32.
