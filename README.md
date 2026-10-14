# RotoTouch OS

Firmware for the RotoCop touch controller: an Arduino with a Seeed 2.8" TFT Touch Shield V2 that acts as a USB keyboard. The screen shows six touch buttons; each one types text or sends a shortcut (copy, paste) to the ground-station computer.

Part of RotoCop, a ground-tethered hexacopter for aerial surveillance and a Florida Tech student team project (Best in Show, Aerospace Engineering, Northrop Grumman Student Design Showcase 2018). As automation lead I built the whole ground station (tether power, video feed and drone automation); this touchpad is a small part of it.

## What it does
- Boot screen with the RotoCop logo and a six-step progress bar, mirrored on the serial port at 9600 baud.
- A 2 × 3 grid of touch buttons, read from the resistive touch panel and mapped to screen coordinates.
- USB HID output through the Arduino `Keyboard` library, with a hold-off between presses.

## Build
Needs a board with native USB HID (Leonardo, Micro or similar), the Seeed `SeeedTouchScreen` and `TFTv2` libraries, and the `Graphx` drawing helpers from [TouchPad-Firmwares](https://github.com/EveAeternam/TouchPad-Firmwares/tree/master/RotoCop/source/lib). Open `RotoCop_TFT_Controller.ino` in the Arduino IDE and upload.

`version` holds the current release; [TouchPad-Editor](https://github.com/EveAeternam/TouchPad-Editor) reads it to tell you when an update is available.

Status: v0.1, September 2017. Not maintained.
