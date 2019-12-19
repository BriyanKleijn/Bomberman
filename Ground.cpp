#include "Ground.h"

Ground::Ground()
{

}

void Ground::Draw(Adafruit_ILI9341 &tft, uint8_t locationX, uint8_t locationY)
{
	tft.fillRect(locationX, locationY, blockSize, blockSize, 0x4D20); // block color
}