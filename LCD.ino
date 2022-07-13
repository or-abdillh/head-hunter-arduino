#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

#define BLACK   0x0000
#define RED     0xF800
#define WHITE   0xFFFF
#define BLUE    0x001F

MCUFRIEND_kbv tft;

void setup() {
  // put your setup code here, to run once:
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.fillScreen(BLACK);
  tft.setCursor(0,30);
  tft.setTextSize(4);
  tft.setTextColor(WHITE);
  tft.print("");

}

void loop() {
  // put your main code here, to run repeatedly:
  tft.setCursor(0,170);
  tft.setTextSize(3);
  tft.setTextColor(BLUE);
  tft.print("");

    tft.setCursor(0,400);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.print("");
}
