#ifndef _GROUNDH_
#define _GROUNDH_
#pragma once
#include "GameObject.h"

class Ground :public GameObject
{
public:
	Ground();
	void Draw(Adafruit_ILI9341 &tft, uint8_t locationX, uint8_t locationY);
};
#endif