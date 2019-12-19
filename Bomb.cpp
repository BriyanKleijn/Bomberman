#include "Bomb.h"


Bomb::Bomb()
{
	bomIsOn = false;
}

Bomb::Bomb(uint8_t &_gameTeller, uint8_t _posX, uint8_t _posY)
{

}

void Bomb::Draw(Adafruit_ILI9341 &tft, uint8_t locationX, uint8_t locationY)
{

}

void Bomb::start(uint8_t &_gameTeller, uint8_t _posX, uint8_t _posY)
{
	bomIsOn = true;


	posX = _posX;
	posY = _posY;

}

void Bomb::Timer() {
	if(bomIsOn){
	_delay_ms(10);

	startTeller++;

	if(startTeller > 500)
	{
		bomExplode = true;
		bomIsOn = false;
	}
}


}

void Bomb::Explosie()
{

}
