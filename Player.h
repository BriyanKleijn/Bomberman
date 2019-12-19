#ifndef _PLAYERH_
#define _PLAYERH_
#pragma once

#include "DrawInterface.h"

#include "Level.h"
#include "Bomb.h"

// player1
#define color_player_darkBlue 0x005F
#define color_player_lightBlue 0x03DF
#define color_player_darkFace1 0xE448
#define color_player_highlightBlue 0x7D9C
#define color_player_lightFace1 0xFD8C
#define color_player_darkShoe1 0x6180
#define color_player_lightShoe1 0x9326
#define color_player_darkHair1 0x6180
#define color_player_lightHair1 0x9326

class Level;
class Player
{

public:
	Player();
	Player(uint8_t player);
	Player(uint8_t player, Level &);

	void Draw(Adafruit_ILI9341 &tft, uint8_t locationX, uint8_t locationY);
	void SpawnPlayer();
	void Move(uint8_t direction);
	void SetCurrentLocation(uint8_t x, uint8_t y);
	void BombDropCheck();
	bool playerMayMove = true;
	Level* level;

private:
	uint8_t lastX, lastY;
	uint8_t posX, posY;


	uint8_t playerDrawDirection;

	bool canDropBomb = true;

	// Bitmaps
	void draw_playerUp_bitmap(Adafruit_ILI9341 &tft, uint8_t x, uint8_t y);
	void draw_playerDown_bitmap(Adafruit_ILI9341 &tft, uint8_t x, uint8_t y);
	void draw_playerLeft_bitmap(Adafruit_ILI9341 &tft, uint8_t x, uint8_t y);
	void draw_playerRight_bitmap(Adafruit_ILI9341 &tft, uint8_t x, uint8_t y);
};
#endif
