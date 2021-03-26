# CESProj4

This project is an arm that *attempts* to play Mary Had A Little Lamb on the water glasses.

## What You Need 
### Software
- Arduino IDE<br />

### Hardware
- ESP32
- SG90 Tower Pro MicroServo
- 28BYJ-48 Step Motor
- ULN2003 Stepper Motor Driver
- wires
- battery

### Connections:
Stepper Motor/Driver: The power and ground are connected to 5V power and ground on the breadboard. In 1 is connected to GPIO 14, In 2 to GPIO 27, In 3 to GPIO 26 and In 4 to GPIO 25. <br/>
Servo Motor: The brown cable is connected to ground on the breadboard, the red is connected to 5V on the breadboard and the orange is connected to GPIO 15 .<br/>

## How To Run (Step by Step):
### ESP32 code<br />
To run wirelessly, enter your wifi name and password and change the UNI in address to your own.<br/>
Upload the .ino file to your ESP32 (or other micro controller).<br/>
Go to the 165.227.76.232:3000/YOUR-UNI address and press the button for it to run.
