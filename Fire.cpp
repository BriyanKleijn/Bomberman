#include "Fire.h"
Fire::Fire()
{

}
Fire::Fire(uint8_t _type)
{
	collision = 3;
	type = _type;
}

// Tekenfunctie
void Fire::Draw(Adafruit_ILI9341 &tft, uint8_t locationX, uint8_t locationY)
{
	switch (type)
	{
	// Horizontaal vuur
	case 0:
		draw_explosionHor(tft, locationX, locationY);
		break;

	// Center explosie
	case 1:
		draw_explosionCenter(tft, locationX, locationY);
		break;

	// Verticaal vuur
	case 2:
		draw_explosionVer(tft, locationX, locationY);
		break;
	}
}

void Fire::draw_explosionCenter(Adafruit_ILI9341 &tft, uint8_t x, uint8_t y) {
	tft.fillRect(x + 3, y, 14, 20, color_player_darkBlue);
	tft.fillRect(x, y + 3, 20, 14, color_player_darkBlue);
	tft.fillRect(x + 4,y, 12, 20, color_player_lightBlue);
	tft.fillRect(x,y + 4, 20, 12, color_player_lightBlue);
	tft.fillRect(x + 6, y, 8, 20, color_player_highlightBlue);
	tft.fillRect(x, y + 6, 20, 8, color_player_highlightBlue);
}

void Fire::draw_explosionHor(Adafruit_ILI9341 &tft, uint8_t x, uint8_t y) {
	tft.fillRect(x, y + 3, 20, 14, color_player_darkBlue);
	tft.fillRect(x, y + 4, 20, 12, color_player_lightBlue);
	tft.fillRect(x, y + 6, 20, 8, color_player_highlightBlue);
}

void Fire::draw_explosionVer(Adafruit_ILI9341 &tft, uint8_t x, uint8_t y) {
	tft.fillRect(x + 3, y, 14, 20, color_player_darkBlue);
	tft.fillRect(x + 4, y, 12, 20, color_player_lightBlue);
	tft.fillRect(x + 6, y, 8, 20, color_player_highlightBlue);
}
