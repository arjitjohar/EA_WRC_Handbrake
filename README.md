# Custom Handbrake for EA WRC using ESP32 and Touch Screen LED

![demo video handbrake - Made with Clipchamp](https://github.com/user-attachments/assets/1d6a75b2-5c80-4b64-851d-67c8836ed4c5)


## Overview
This project involves creating a custom handbrake for EA WRC using an ESP32 microcontroller and a touch screen LED. It provides a unique way to enhance your gaming experience by integrating physical controls with the game.

## Table of Contents
- [Project Description](#project-description)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation Steps](#installation-steps)
- [Usage Examples](#usage-examples)
- [Support Information](#support-information)

## Project Description
This custom handbrake is designed to work seamlessly with EA WRC, providing a more immersive gaming experience. The ESP32 microcontroller handles the communication between the handbrake and the game, while the touch screen LED offers intuitive control and feedback.

### Features
- **ESP32 Microcontroller**: Handles game interactions and sensor data.
- **Touch Screen LED**: Provides visual feedback and user interface.
- **Customizable**: Allows users to adjust settings for optimal performance.

## Hardware Requirements
- **ESP32 Board**: Any compatible ESP32 board (e.g., ESP32 DevKitC).
- **Touch Screen LED Display**: A compatible TFT LCD touchscreen display (e.g., 2.8 inch ILI9341).
- **Breadboard and Jumper Wires**: For connecting components.
- **Power Supply**: For the ESP32 and display.

## Software Requirements
- **Arduino IDE**: For programming the ESP32.
- **ESP32 Board Package**: Install via Arduino IDE's Board Manager.
- **TFT Library**: For interacting with the touchscreen display.
- **MCEC Controller** For settin up communication between your PC and the microcontroller. Can be downloaded from here: https://github.com/tig/mcec/blob/40adcafe8ee8269d36d7c1a2df78227989695490/src/Commands/SendInputCommand.cs#L271
- 

## Installation Steps
1. **Install Arduino IDE**: Download and install from [arduino.cc](https://www.arduino.cc/en/Main/Software).
2. **Add ESP32 Board Package**:
   - Open Arduino IDE, go to **File** > **Preferences**.
   - Add `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json` to **Additional Board Manager URLs**.
   - Go to **Tools** > **Board** > **Boards Manager...**, search for **ESP32**, and install.
3. **Install TFT Library**:
   - Open Arduino IDE, go to **Sketch** > **Include Library** > **Manage Libraries...**.
   - Search for and install the TFT library compatible with your display (e.g., Adafruit ILI9341).
4. **Connect Hardware**:
   - Wire the TFT display and touch screen to the ESP32 according to the pinout diagram.
   - Connect power to the ESP32 and display.
5. **Upload Code**:
   - Open the provided Arduino sketch.
   - Select the correct ESP32 board and COM port.
   - Upload the code to the ESP32.

## Usage Examples
- **Setup**: Connect the handbrake to your gaming setup and ensure it's recognized by the game.
- **Calibration**: Adjust settings via the touch screen interface for optimal performance.

## Support Information
If you like this project, consider starring it on GitHub!

