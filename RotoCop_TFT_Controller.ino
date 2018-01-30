/*
 * ROTOcop - Touch Controller OS
 * v0.1 (09/11/2017) by Evangeline Archer
 */

#include <SD.h>
#include <SPI.h>
#include <SeeedTouchScreen.h>
#include <TFTv2.h>
#include <Keyboard.h>
#include <Graphx.h>
#include <stdint.h>

TouchScreen ts = TouchScreen(XP, YP, XM, YM);

// VARIABLE DECLARATIONS
char* buttons[]={"HW!", "RC", "1","2","COPY","PASTE"};
char* instText[]={"Starting serial on Baud 9600...", "Initiating TFT...", "Initiating HID...","Loading custom settings...","Done.","Starting OS"};
int keyPressHold = 600;

void setup() {
  Serial.begin(9600);
  Tft.TFTinit();
  boot(2000);
}

void loop() {
  
  Point p = ts.getPoint();
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 240);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 320);

    if (p.z > __PRESURE) {
        // Detect  paint brush color change
        if (p.x < HALF_X) {
          //LEFT BUTTONS
          if (p.y < THIRD_Y) {
            Serial.println("1");
            Keyboard.println("Hello World!");
          } else if (p.y > THIRD_Y && p.y < THIRD_Y*2) {
            Serial.println("3");
            Keyboard.print("1");
          } else {
            Serial.println("5");
            hkCopy();
          }
        } else {
          //RIGHT BUTTONS
          if (p.y < THIRD_Y) {
            Serial.println("2");
            Keyboard.println("RotoCop");
          } else if (p.y > THIRD_Y && p.y < THIRD_Y*2) {
            Serial.println("4");
            Keyboard.print("2");
          } else {
            Serial.println("6");
            hkPaste();
          }
        }
    delay(keyPressHold);
    }
}

void boot(int bootTime) {
  
  int barX = THIRD_X/2+1;
  int gap = 1;
  int box = 6;
  int boxX = THIRD_X*2/box;
  int wt = bootTime / box;

  Gfx.rotoCopLogo(HALF_X,60);
  Gfx.drawUI();

  for (int i = 0; i < box; i++){
    Tft.fillRectangle(barX+1+gap+(boxX*i),242,boxX-gap,17,GREEN);
    Serial.println("Boot [" + String(i+1) + "]: " + instText[i]);
    Tft.drawString(instText[i],5,270,1,GRAY2);
    bootIns(i);
    delay(wt);
    Tft.fillRectangle(0,270,240,8,BLACK);
  }

  delay(1000);
  Tft.fillScreen();

  Gfx.drawSixBoxes();

  Tft.drawString(buttons[0],SCREEN_X/8,THIRD_Y/2,2,WHITE);
  Tft.drawString(buttons[1],SCREEN_X/8*5,THIRD_Y/2,2,WHITE);

  Tft.drawString(buttons[2],SCREEN_X/8,THIRD_Y/2*3,2,WHITE);
  Tft.drawString(buttons[3],SCREEN_X/8*5,THIRD_Y/2*3,2,WHITE);

  Tft.drawString(buttons[4],SCREEN_X/8,THIRD_Y/2*5,2,WHITE);
  Tft.drawString(buttons[5],SCREEN_X/8*5,THIRD_Y/2*5,2,WHITE);
}

void bootIns(int val) {
  switch (val) {
    case 0:
      Serial.println("Serial Com is now running on Baud 9600");
      break;
    case 1:
      
      break;
    case 2:
      Keyboard.begin();
      break;
    case 3:
      
      break;
    case 4:

      break;
    case 5:
      Serial.println("End of POST");
      break;
  }
}

void hkCopy() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('c');
  delay(100);
  Keyboard.releaseAll();
}

void hkPaste() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('v');
  delay(100);
  Keyboard.releaseAll();
}

