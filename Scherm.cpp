#include "Scherm.h"

Scherm::Scherm(Adafruit_ILI9341 &_tft)
{
	tft = &_tft;
}

void Scherm::getHighScore()
{

}

void Scherm::draw_text(uint8_t Xloc, uint8_t Yloc, uint8_t size, char* text, uint16_t colour) {
  tft->setCursor(Xloc, Yloc);
  tft->setTextColor(colour);
  tft->setTextSize(size);
  tft->print(text);
}
