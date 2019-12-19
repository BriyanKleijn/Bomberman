#ifndef _LEVELH_
#define _LEVELH_
#pragma once
#include "Bomb.h"
#include "DrawInterface.h"
#include "GameObject.h"
#include "Ground.h"
#include "Wall.h"
#include "Player.h"
#include "Crate.h"

#include "Fire.h"

#define blockSize 20		 // grootte tussen blokjes
#define gridSize 11			 // aantal blokjes op grid
#define startingPoint 10	 // afstand vanaf 0punt van scherm
#define startingPouint8_t 10 // afstand vanaf 0punt van scherm

#define ground_index 0
#define wall_index 1
#define destructable_index 2
#define bomb_index 3
#define player_index 5

#ifndef __FOO_H_DEFINED
			 #define __FOO_H_DEFINED
			 class Level;
			 class Bomb;
			 #include "Bomb.h"
	 #endif

class Level : public DrawInterface
{
public:
	Level();
	Level(Adafruit_ILI9341 &, uint8_t &);

	// Alle arraysBomb
	int levelObj[11][11];// Lijst met gameobjecten
	int levelBomb[11][11];// Lijst met bommen

	GameObject *objects[5];// Alle verschillende soorten gameobjecten
	Fire fire[2];// Alle typen vuur

	Ground ground;
	Wall wall;
	Crate crate;
	Bomb *bomb[4];

	Bomb bomb1, bomb2, bomb3, bomb4, bomb5;

	GameObject getLevel();

	bool CheckCollision(uint8_t x, uint8_t y);
	bool CheckForDeath(uint8_t x, uint8_t y);

	uint8_t* gameTimer;

	void Loop();
	void Timer();

	void DrawLevel();
	void SetLevel();

	void AddBomb(uint8_t x, uint8_t y);
	void RemoveBomb(uint8_t x, uint8_t y);

	void set_wall_vert(uint8_t x_start);
	void set_wall_hor(uint8_t y_start);
	void set_pillar_wall();

	void set_crates();
	void unset_crates();

	void setAmountOfCrates(uint8_t amount);
	uint8_t getAmountOfCrates();

	void line_grid(uint8_t y);
	void grid();

	uint8_t location(uint8_t coordinate);
	Adafruit_ILI9341 *tft;

private:
	uint8_t amCrates = 23;
};
#endif
