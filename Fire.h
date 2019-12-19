#include "GameObject.h"

#define color_player_highlightBlue 0x7D9C
#define color_player_darkBlue 0x005F
#define color_player_lightBlue 0x03DF

class Fire :public GameObject
{
public:
	Fire();
	Fire(uint8_t _type);// Geeft het type vuur mee, zoals linker, midden, rechts of omhoog
	uint8_t type;

	void Draw(Adafruit_ILI9341 &tft, uint8_t locationX, uint8_t locationY);

private:
	void draw_explosionCenter(Adafruit_ILI9341 &tft, uint8_t x, uint8_t y);
	void draw_explosionHor(Adafruit_ILI9341 &tft, uint8_t x, uint8_t y);
	void draw_explosionVer(Adafruit_ILI9341 &tft, uint8_t x, uint8_t y);
};
