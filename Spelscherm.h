#ifndef _SPELSCHERMH_
#define _SPELSCHERMH_
#pragma once
#include "Scherm.h"
#include "Level.h"
#include "Player.h"
#include <avr/io.h>

class Spelscherm:public Scherm
{
public:
	Level* level;
	Player player;
	Adafruit_ILI9341* tft;
	//Input input;
	void Do();
	void DrawLevel();
	Spelscherm(Adafruit_ILI9341 &_tft, Level &_level) :Scherm(_tft){
		tft = &_tft;
		level = &_level;
	}

	void PlayerInfoBar();
	void draw_playerName(uint8_t Xloc, uint8_t Yloc, uint8_t player);



private:

};
#endif
