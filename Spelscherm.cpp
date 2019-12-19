#include "Spelscherm.h"

void Spelscherm::PlayerInfoBar()
{

}

void Spelscherm::DrawLevel(){


}


void Spelscherm::draw_playerName(uint8_t Xloc, uint8_t Yloc, uint8_t player) {
  cli();
  char p[4] = "P3";
  p[1] = (char) player+48;//+48 to turn the number to a char
  uint16_t colour = ILI9341_BLUE;
  if (player == 1) {
    colour = ILI9341_BLUE;
  } else if (player == 2) {
    colour = ILI9341_RED;
  }
  tft->fillRect(Xloc, Yloc, blockSize, blockSize, colour);
  tft->drawRect(Xloc, Yloc, blockSize, blockSize, ILI9341_BLACK);
  draw_text(Xloc + blockSize * 1 + blockSize / 2, Yloc, 2, p, colour);
  sei();
}

void Spelscherm::Do()
{
	//input.loop();
}
