# Smart RFID-Based Checkout System using ESP32

## Overview

The Smart RFID-Based Checkout System is an embedded IoT project designed to automate the product billing process in retail environments.

The system uses RFID technology to identify products, calculate the total bill automatically, display information on an LCD screen, and provide user feedback through a buzzer.

This project demonstrates practical implementation of:

- ESP32 Microcontroller
- RFID Communication
- SPI Protocol
- I2C Communication
- LCD Interfacing
- Embedded C Programming
- IoT and Retail Automation Concepts

---

## Features

✔ RFID-based product identification

✔ Automatic bill calculation

✔ Real-time LCD display

✔ Audio indication using buzzer

✔ Product addition through RFID tag scanning

✔ Total amount calculation

✔ Low-cost retail automation solution

---

## Hardware Components

| Component | Quantity |
|------------|------------|
| ESP32 Development Board | 1 |
| RC522 RFID Reader Module | 1 |
| RFID Tags/Cards | Multiple |
| 16x2 LCD with I2C Module | 1 |
| Active Buzzer | 1 |
| Push Button | 1 |
| Breadboard | 1 |
| Jumper Wires | Multiple |
| 5V Power Supply | 1 |

---

## Circuit Connections

### RC522 RFID Module → ESP32

| RC522 Pin | ESP32 Pin |
|------------|------------|
| SDA | GPIO 5 |
| SCK | GPIO 18 |
| MOSI | GPIO 23 |
| MISO | GPIO 19 |
| RST | GPIO 4 |
| 3.3V | 3.3V |
| GND | GND |

---

### LCD Display (I2C)

| LCD Pin | ESP32 Pin |
|----------|-----------|
| SDA | GPIO 21 |
| SCL | GPIO 22 |
| VCC | 5V |
| GND | GND |

---

### Buzzer

| Buzzer Pin | ESP32 Pin |
|------------|------------|
| Positive | GPIO 15 |
| Negative | GND |

---

### Push Button

| Button Pin | ESP32 Pin |
|------------|------------|
| Signal | GPIO 13 |
| Other End | GND |

---

## Working Principle

1. User scans RFID-tagged products.
2. ESP32 reads RFID UID through RC522 module.
3. UID is matched with stored product information.
4. Product name and price are displayed on LCD.
5. Product amount is added to total bill.
6. Buzzer confirms successful scan.
7. Final amount is displayed continuously.
8. Push button can be used for checkout/reset operations.

---

## Software Used

- Arduino IDE
- ESP32 Board Package
- MFRC522 Library
- Wire Library
- LiquidCrystal_I2C Library

---

## Embedded Concepts Implemented

- SPI Communication
- I2C Communication
- GPIO Handling
- RFID Technology
- Real-Time Embedded Processing
- Peripheral Interfacing
- Event Driven Programming

---

## Applications

- Supermarkets
- Smart Shopping Carts
- Automated Billing Systems
- Inventory Tracking
- Retail Automation
- IoT Retail Solutions

---

## Future Improvements

- Cloud Database Integration
- Mobile App Connectivity
- WiFi Billing Dashboard
- Online Payment Gateway
- Inventory Management
- Customer Analytics
- Receipt Generation

---

## Project Images

Attached

---

## Author

Yug Shah

Electronics and Communication Engineering


