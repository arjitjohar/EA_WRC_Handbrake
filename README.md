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
- **Customizable**: Allows users to adjust settings for desired usecase.

## Hardware Requirements
- **ESP32 Board**: The one I am using for this project is Waveshares ESP32-S3 development board. It can be found [here](https://www.amazon.ca/dp/B0CM68M8LR?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1).
- **Touch Screen LED Display**: A compatible TFT LCD touchscreen display (e.g., 2.8 inch ILI9341).
- **USB cable type A to type C connector**: For connecting the microcontroller to your PC running WRC.

## Software Requirements
- **Arduino IDE**: For programming the ESP32.
- **ESP32 Board Package**: Install via Arduino IDE's Board Manager.
- **TFT Library**: For interacting with the touchscreen display.
- **MCEC Controller** For setting up communication between your PC and the microcontroller. Can be downloaded from [here](https://github.com/tig/mcec/blob/40adcafe8ee8269d36d7c1a2df78227989695490/src/Commands/SendInputCommand.cs#L271).
- **AutoHotKey**: For some reason, EA WRC does not like the way buttons are being inputted when triggered through MCEC controller, so we need a script to workaround that. It can be installed from [here](https://www.autohotkey.com/).

## Installation Steps
1. **Install Arduino IDE**: Download and install from [arduino.cc](https://www.arduino.cc/en/Main/Software).
2. **Add ESP32 Board Package**:
   - Follow the getting started guide to get your micro controller working with arduino [link](https://www.waveshare.com/wiki/ESP32-S3-LCD-1.28#Overview). This is the guide for the Waveshare ESP32-S3 controller.
3. **Ensure Package Dependancies Are Met**
   - The easiest way to make sure the package dependancies are met is to run the code in the `ESP32-S3-Touch-LCD-1.28-Test` folder. I have included the folder if you do not have it from the Waveshare ESP32-S3 controller tutorial.
4. **Setup MCE Controller**
   - Find the `AppData\Roaming\Kindel` Systems directory and replace the `MCEControl.COMMANDS` file with the one attached in this folder. This will update which enabled commands are allowed to be executed with the MCEC Controller.
   - Setup the client as ```localhost:5150``` as that is the port we will be communicating through for the microcontroller.

      ![image](https://github.com/user-attachments/assets/7dd124cf-1956-4b72-ae78-7b6e54e74559)

   - Setup the server as `5150`, same port as the one from the client to open communication.
     ![image](https://github.com/user-attachments/assets/f4146aeb-c1cf-405e-8cb4-3cbce5d68d5c)
   - Setup the serial server dependant on what COM port your microcontroller is using and what baudrate it uses as well. How to find these can be found from the documentation of your microcontroller.
   ![image](https://github.com/user-attachments/assets/4b724937-104e-4b04-bd18-f05c55936081)

4. **Run the AHK Script**
   - Click and run the included .AHK script to rebind MBD and MBUP button to the "E" key up / down on your keyboard for WRC.
   - rebind the handbrake on WRC to be the "E" key instead as below
      ![image](https://github.com/user-attachments/assets/7eeb8c3e-b4b8-4cc0-b204-64ca6cb6c007)

6. **Upload Code**:
   - Open the provided Arduino sketch.
   - Select the correct ESP32 board and COM port.
   - Upload the code to the ESP32.


## Usage Examples
- This code can be expanded upon further to be used with other racing games. This would be done by changing the settings in whatever game you are working with
## References
- Technical documentation regarding esp32-s3 microcontrollers: [link](https://files.waveshare.com/wiki/common/Esp32-s3_technical_reference_manual_en.pdf)
- Getting started guide with the microcontroller: [link](https://www.waveshare.com/wiki/ESP32-S3-LCD-1.28#Overview)
- Understanding how usb works on the esp32s3 works: [link](https://www.youtube.com/watch?v=hJSBTFsOnoA&ab_channel=AndreasSpiess)
- MCEC documentation: [link](https://tig.github.io/mcec/documentation.html)
## Support Information
If you like this project, consider starring it on GitHub!

