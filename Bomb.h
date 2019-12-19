#ifndef _BOMBH_
#define _BOMBH_
#pragma once
#include "GameObject.h"


#define ExplosieTijd 500 // Tijd is in 0.01 variant, dus in dit geval 5 seconden

class Bomb :public GameObject
{

public:
	Bomb();
	Bomb(uint8_t &, uint8_t _posX, uint8_t _posY);

	bool bomIsOn = false;// If the bom is running#include "Level.h"
	bool bomExplode = false;

	uint16_t startTeller = 0;


	void Timer();
	void Draw(Adafruit_ILI9341 &tft, uint8_t locationX, uint8_t locationY);
	void start(uint8_t &, uint8_t _posX, uint8_t _posY);
	uint8_t posX, posY;

private:
	void Explosie();


};
#endif
