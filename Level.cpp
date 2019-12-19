#include "Level.h"
Player player;


Level::Level()
{
}

Level::Level(Adafruit_ILI9341 &_tft, uint8_t &_gametimer)
{
	tft = &_tft;


	// Alle indexen
	objects[0] = &ground;
	objects[1] = &wall;
	objects[2] = &crate;
	// zet de gametimer
	gameTimer = &_gametimer;

	bomb[0] = &bomb1;
	bomb[1] = &bomb2;
	bomb[2] = &bomb3;
	bomb[3] = &bomb4;
	bomb[4] = &bomb5;

}

GameObject Level::getLevel()
{
	return GameObject();
}

void Level::Loop()
{
}

bool Level::CheckCollision(uint8_t x, uint8_t y)
{
	return false;
}

bool Level::CheckForDeath(uint8_t x, uint8_t y)
{
	if (objects[levelObj[x][y]]->collision == 3) // De collision value 3 geeft aan dat het object damage doet, in dit geval vuur
	{
		return true;
	}
	else {
		return false;
	}
}

// Hierin kun je het level laten generen, dus aanvullen van de array
void Level::SetLevel()
{
	set_wall_vert(11);
	set_wall_hor(0);
	set_wall_hor(1);
	set_wall_vert(0);
	set_wall_vert(1);
	set_pillar_wall();
	set_crates();
	// // De loop voor de multi array
	// for (int row = 0; row < 11; row++)
	// {
	// 	for (int col = 0; col < 11; col++)
	// 	{
	// 		// IN dit stuk kun je nu het juiste element aanroepen
	// 		levelObj[row][col] = 1;
	// 	}
	// }
}

void Level::AddBomb(uint8_t x, uint8_t y)
{

	bool setBomb = false;

		for (int i = 0; i < 4; i++)
		{
			if (!setBomb) {
				if (bomb[i]->bomIsOn) {
					// Gebeurd er niks
				}
				else {
					// Zet de bom
					bomb[i]->start(*gameTimer, x, y);
					levelBomb[x][y] = 1;
					setBomb = true; // bom is gezet
				}
			}
		}
}

void Level::Timer(){
	for(int i = 0; i<4; i++)
	{
			bomb[i]->Timer();
			if(bomb[i]->bomExplode){
				RemoveBomb(bomb[i]->posX, bomb[i]->posY);
				bomb[i]->bomExplode = false;
			}
	}
}

void Level::RemoveBomb(uint8_t x, uint8_t y)
{
	levelBomb[x][y] = 0;
	DrawLevel();
}

void Level::set_crates()
{
	unset_crates(); // rid the level of destructibles
	uint8_t dLocationX;
	uint8_t dLocationY;
	uint8_t i = 0;
	while (i < getAmountOfCrates())
	{ // check on collision with new box
		dLocationX = (rand() % 9) + 1;
		dLocationY = (rand() % 9) + 1;
		if (!((dLocationX == 1 && dLocationY == 1) || // spawn 1
			  (dLocationX == 1 && dLocationY == 2) ||
			  (dLocationX == 2 && dLocationY == 1) ||

			  (dLocationX == 9 && dLocationY == 9) || // spawn 2
			  (dLocationX == 9 && dLocationY == 8) ||
			  (dLocationX == 8 && dLocationY == 9) ||

			  (levelObj[dLocationX][dLocationY] == wall_index) || // other object
			  (levelObj[dLocationX][dLocationY] == destructable_index)))
		{
			levelObj[dLocationX][dLocationY] = destructable_index;
			i++;
		}
	}
}

void Level::unset_crates()
{ // rid the level of instructibles
	for (uint8_t X = 1; X < gridSize; X++)
	{
		for (uint8_t Y = 1; Y < gridSize; Y++)
		{
			if (levelObj[X][Y] == destructable_index)
			{
				levelObj[X][Y] = ground_index;
			}
		}
	}
}

void Level::set_wall_vert(uint8_t x_start)
{ // if x == true: draw left wall, if x == false: draw right wall
	uint8_t x;
	if (x_start)
	{
		x = 0;
	}
	else
	{
		x = 10;
	}
	for (uint8_t y = 1; y <= 9; y++)
	{
		levelObj[x][y] = wall_index;
	}
}

void Level::set_wall_hor(uint8_t y_start)
{ // if y == true: draw up wall, if y == false: draw down wall
	uint8_t y;
	if (y_start)
	{
		y = 0;
	}
	else
	{
		y = 10;
	}
	for (uint8_t x = 0; x <= 10; x++)
	{
		levelObj[x][y] = wall_index;
	}
}

void Level::set_pillar_wall()
{ // draw field pillars
	uint8_t y;
	for (uint8_t x = 2; x <= 8; x += 2)
	{
		for (y = 2; y <= 8; y += 2)
		{
			levelObj[x][y] = wall_index;
		}
	}
}

void Level::DrawLevel()
{
	// De loop voor de multi array
	for (int row = 0; row < 11; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			// IN dit stuk kun je nu het juiste element aanroepen
			objects[levelObj[row][col]]->Draw(*tft, location(row), location(col));

			// Tekenen van de bom
			if (levelBomb[row][col]==1) {
				objects[2]->Draw(*tft, location(row), location(col));
			}
		}
	}
}

uint8_t Level::location(uint8_t coordinate)
{
	return blockSize * coordinate + startingPoint;
}

void Level::setAmountOfCrates(uint8_t amount)
{
	amCrates = amount;
}
uint8_t Level::getAmountOfCrates()
{
	return amCrates;
}
