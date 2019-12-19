#include "Player.h"


Player::Player()
{

}

Player::Player(uint8_t player)
{

}

// Player constructor
Player::Player(uint8_t player, Level &_level)
{
	level = &_level;// Zet de reference
	posX = 2;// Start positie
	posY = 2;// Start positie
	playerDrawDirection = 1;// Standaard direction
}

// Zorgt voor het drawen van de functie
void Player::Draw(Adafruit_ILI9341 &tft, uint8_t locationX, uint8_t locationY) {
	switch (playerDrawDirection) {
	case 1://up
		draw_playerUp_bitmap(tft, locationX, locationY);
		break;

	case 2://down
		draw_playerDown_bitmap(tft, locationX, locationY);
		break;

	case 3://right
		draw_playerRight_bitmap(tft, locationX, locationY);
		break;
	case 4://left
		draw_playerLeft_bitmap(tft, locationX, locationY);
		break;
	}

}

void Player::draw_playerUp_bitmap(Adafruit_ILI9341 &tft,uint8_t x, uint8_t y) {
	// body
	tft.fillRect(x + 2, y + 9, 16, 4, color_player_lightBlue);
	tft.drawFastVLine(x + 1, y + 9, 3, color_player_darkBlue);
	tft.drawFastHLine(x + 2, y + 12, 2, color_player_darkBlue);
	tft.drawFastHLine(x + 4,y + 13, 12, color_player_darkBlue);
	tft.drawFastHLine(x + 16, y + 12, 2, color_player_darkBlue);
	tft.drawFastHLine(x + 2, y + 8, 2, color_player_highlightBlue);
	tft.drawFastHLine(x + 16, y + 8, 2, color_player_highlightBlue);
	tft.drawFastVLine(x + 18, y + 9, 3, color_player_highlightBlue);

	// hat
	tft.fillRect(x + 5, y + 5, 10, 4, color_player_lightBlue);
	tft.fillRect(x + 9, y+ 6, 2, 3, color_player_darkBlue);
	tft.drawPixel(x + 8, y + 7, color_player_darkBlue);
	tft.drawPixel(x + 11, y + 7, color_player_darkBlue);
	tft.drawPixel(x + 5, y + 5, color_player_darkBlue);
	tft.drawPixel(x+ 5,y + 9, color_player_darkBlue);
	tft.drawPixel(x + 14, y + 9, color_player_darkBlue);
	tft.drawFastVLine(x + 4, y + 6, 3, color_player_darkBlue);
	tft.drawFastHLine(x + 6, y + 10, 8, color_player_darkBlue);
	tft.drawFastHLine(x + 6, y + 4, 8, color_player_highlightBlue);
	tft.drawPixel(x + 14, y + 5, color_player_highlightBlue);
	tft.drawFastVLine(x+ 15, y + 6, 3, color_player_highlightBlue);
	// hair
	tft.drawFastVLine(x + 4, y + 9, 2, color_player_darkHair1);
	tft.drawFastHLine(x + 5, y + 11, 3, color_player_darkHair1);
	tft.drawFastHLine(x + 8,y + 12, 4, color_player_darkHair1);
	tft.drawFastHLine(x + 12, y + 11, 3, color_player_darkHair1);
	tft.drawFastVLine(x + 15, y + 9, 2, color_player_darkHair1);
	tft.drawPixel(x + 5, y+ 10, color_player_lightHair1);
	tft.drawFastHLine(x + 8, y + 11, 4, color_player_lightHair1);
	tft.drawPixel(x+ 14, y + 10, color_player_lightHair1);
	// shoes
	tft.drawFastHLine(x + 5, y + 14, 3, color_player_darkShoe1);
	tft.drawFastHLine(x + 12, y + 14, 3, color_player_darkShoe1);
}


void Player::draw_playerDown_bitmap(Adafruit_ILI9341 &tft,uint8_t x, uint8_t y) {
	/*
	tft.fillRect(location(x), location(y), blockSize, blockSize, ILI9341_BLUE);
	tft.drawRect(location(x), location(y), blockSize, blockSize, ILI9341_BLACK);
	*/
	// face
	tft.fillRect(x + 5, y + 10, 10, 3, color_player_darkFace1);
	tft.drawFastHLine(x + 9,y + 13, 2, color_player_darkFace1);
	tft.drawFastHLine(x + 6, y+ 11, 8, color_player_lightFace1);
	tft.drawFastHLine(x+ 9, y + 12, 2, color_player_lightFace1);
	tft.drawPixel(x + 7, y + 11, ILI9341_WHITE);
	tft.drawPixel(x + 8,y + 11, ILI9341_BLACK);
	tft.drawPixel(x + 11, y + 11, ILI9341_BLACK);
	tft.drawPixel(x + 12, y + 11, ILI9341_WHITE);

	// hat + clothing
	tft.fillRect(x + 5, y + 5, 10, 5, color_player_lightBlue);
	tft.drawFastHLine(x + 6, y + 4, 8, color_player_highlightBlue);
	tft.drawFastHLine(x + 6, y + 10, 8, color_player_darkBlue);
	tft.drawFastHLine(x + 6, y + 10, 8, color_player_darkBlue);
	tft.fillRect(x + 9, y + 5, 2, 3, color_player_darkBlue);
	tft.drawPixel(x + 8, y + 6, color_player_darkBlue);
	tft.drawPixel(x + 11, y + 6, color_player_darkBlue);
	tft.drawPixel(x + 5, y + 5, color_player_darkBlue);
	tft.drawPixel(x + 14, y + 5, color_player_highlightBlue);
	tft.drawPixel(x + 5, y + 9, color_player_darkBlue);
	tft.drawPixel(x + 14, y + 9, color_player_darkBlue);
	tft.drawFastVLine(x + 4, y + 6, 6, color_player_darkBlue);
	tft.drawFastVLine(x + 4, y + 9, 2, color_player_highlightBlue);
	tft.drawFastVLine(x + 15, y + 6, 3, color_player_highlightBlue);
	tft.drawFastVLine(x + 15, y + 9, 3, color_player_darkBlue);
	tft.drawFastHLine(x + 2, y + 7, 2, color_player_highlightBlue);
	tft.drawFastHLine(x + 2, y + 11, 2, color_player_darkBlue);
	tft.drawFastHLine(x + 16, y + 7, 2, color_player_highlightBlue);
	tft.drawFastHLine(x + 16, y + 11, 2, color_player_darkBlue);
	tft.fillRect(x + 2, y + 8, 2, 3, color_player_lightBlue);
	tft.fillRect(x + 16, y + 8, 2, 3, color_player_lightBlue);
	tft.drawFastVLine(x + 1, y + 8, 3, color_player_darkBlue);
	tft.drawFastVLine(x + 18, y + 8, 3, color_player_highlightBlue);

	// shoes
	tft.fillRect(x + 5, y + 13, 3, 2, color_player_darkShoe1);
	tft.fillRect(x+ 12, y + 13, 3, 2, color_player_darkShoe1);
	tft.drawPixel(x + 5, y + 12, color_player_darkShoe1);
	tft.drawPixel(x + 14, y + 13, color_player_darkShoe1);
	tft.drawPixel(x + 6, y+ 13, color_player_lightShoe1);
	tft.drawPixel(x + 13, y + 13, color_player_lightShoe1);
}

void Player::draw_playerLeft_bitmap(Adafruit_ILI9341 &tft,uint8_t x, uint8_t y) {
	// face
	tft.drawFastHLine(x + 8, y + 4, 2, color_player_darkFace1);
	tft.drawFastVLine(x + 7, y + 5, 7, color_player_darkFace1);
	tft.drawFastVLine(x + 6, y + 7, 2, color_player_darkFace1);
	tft.drawFastHLine(x + 8, y + 12, 3, color_player_darkFace1);
	tft.drawFastHLine(x + 7, y + 7, 2, color_player_lightFace1);
	tft.fillRect(x + 8, y + 10, 2, 2, color_player_lightFace1);
	tft.drawPixel(x + 8, y + 5, ILI9341_WHITE);
	tft.drawPixel(x + 8, y + 6, ILI9341_BLACK);
	tft.drawPixel(x + 8, y + 8, ILI9341_BLACK);
	tft.drawPixel(x + 8, y + 9, ILI9341_WHITE);
	// hair
	tft.drawPixel(x + 10, y + 11, color_player_darkHair1);
	tft.drawFastHLine(x + 11, y + 12, 3, color_player_darkHair1);
	// hat
	tft.fillRect(x + 10, y + 4, 5, 7, color_player_lightBlue);
	tft.drawFastVLine(x + 9, y + 5, 5, color_player_darkBlue);
	tft.drawPixel(x + 10, y + 10, color_player_darkBlue);
	tft.drawFastHLine(x + 11, y + 11, 4, color_player_darkBlue);
	tft.drawPixel(x + 14, y + 10, color_player_darkBlue);
	tft.drawFastVLine(x + 15, y + 7, 4, color_player_darkBlue);
	tft.fillRect(x + 12, y + 6, 3, 2, color_player_darkBlue);
	tft.drawPixel(x + 13, y + 5, color_player_darkBlue);
	tft.drawPixel(x + 13, y + 8, color_player_darkBlue);
	tft.drawPixel(x + 10, y + 4, color_player_highlightBlue);
	tft.drawFastHLine(x + 11, y + 3, 3, color_player_highlightBlue);
	tft.drawPixel(x + 14, y + 4, color_player_highlightBlue);
	tft.drawFastVLine(x + 15, y + 5, 2, color_player_highlightBlue);
	// left arm
	tft.fillRect(x + 9, y + 13, 3, 4, color_player_lightBlue);
	tft.drawFastVLine(x + 8, y + 13, 4, color_player_darkBlue);
	tft.drawFastHLine(x + 9, y + 15, 3, color_player_darkBlue);
	tft.drawFastHLine(x + 9, y + 17, 3, color_player_darkBlue);
	tft.drawPixel(x + 12, y + 16, color_player_darkBlue);
	tft.drawFastVLine(x + 12, y + 13, 3, color_player_highlightBlue);
	tft.drawPixel(x + 8, y + 17, color_player_darkFace1);
	tft.drawFastHLine(x + 9, y + 18, 2, color_player_darkFace1);
	// right arm
	tft.drawFastHLine(x + 9, y + 2, 3, color_player_lightBlue);
	tft.drawPixel(x + 8, y + 2, color_player_darkBlue);
	tft.drawFastHLine(x + 8, y + 3, 3, color_player_darkBlue);
	tft.drawFastHLine(x + 9, y+ 1, 3, color_player_highlightBlue);
	tft.drawPixel(x + 12, y + 2, color_player_highlightBlue);
	// right shoe
	tft.drawPixel(x + 6, y + 5, color_player_darkShoe1);
	tft.drawFastVLine(x + 5, y+ 6, 2, color_player_darkShoe1);
	tft.drawPixel(x + 6, y + 6, color_player_lightShoe1);
	// left shoe
	tft.drawPixel(x + 6, y + 11, color_player_darkShoe1);
	tft.drawFastVLine(x + 5, y + 12, 2, color_player_darkShoe1);
	tft.drawFastHLine(x + 6, y + 13, 2, color_player_darkShoe1);
	tft.drawFastHLine(x + 6, y + 12, 2, color_player_lightShoe1);
}

void Player::draw_playerRight_bitmap(Adafruit_ILI9341 &tft, uint8_t x, uint8_t y) {
	// face
	tft.drawFastHLine(x + 10, y + 4, 2, color_player_darkFace1);
	tft.drawFastVLine(x + 12, y + 5, 2, color_player_darkFace1);
	tft.drawFastVLine(x + 13, y + 7, 2, color_player_darkFace1);
	tft.drawFastVLine(x + 12, y + 8, 4, color_player_darkFace1);
	tft.drawFastHLine(x + 9, y + 12, 3, color_player_darkFace1);
	tft.drawFastHLine(x + 11, y + 7, 2, color_player_lightFace1);
	tft.fillRect(x + 10, y + 10, 2, 2, color_player_lightFace1);
	tft.drawPixel(x + 11, y + 5, ILI9341_WHITE);
	tft.drawPixel(x + 11, y + 6, ILI9341_BLACK);
	tft.drawPixel(x + 11, y + 8, ILI9341_BLACK);
	tft.drawPixel(x + 11, y + 9, ILI9341_WHITE);
	// hair
	tft.drawPixel(x + 9, y + 11, color_player_darkHair1);
	tft.drawFastHLine(x + 6, y + 12, 3, color_player_darkHair1);
	// hat
	tft.fillRect(x + 5, y + 4, 5, 7, color_player_lightBlue);
	tft.drawFastVLine(x + 4, y + 5, 6, color_player_darkBlue);
	tft.drawFastVLine(x + 5, y + 10, 2, color_player_darkBlue);
	tft.drawFastHLine(x + 6, y + 11, 3, color_player_darkBlue);
	tft.drawPixel(x + 9, y + 10, color_player_darkBlue);
	tft.drawFastVLine(x + 10, y + 7, 3, color_player_darkBlue);
	tft.fillRect(x + 5, y + 6, 3, 2, color_player_darkBlue);
	tft.drawPixel(x + 6, y + 5, color_player_darkBlue);
	tft.drawPixel(x + 6, y + 8, color_player_darkBlue);
	tft.drawPixel(x + 5, y + 4, color_player_highlightBlue);
	tft.drawFastHLine(x + 6, y + 3, 3, color_player_highlightBlue);
	tft.drawPixel(x + 9, y + 4, color_player_highlightBlue);
	tft.drawFastVLine(x + 10, y + 5, 2, color_player_highlightBlue);
	// left arm
	tft.drawFastHLine(x + 8, y + 2, 3, color_player_lightBlue);
	tft.drawPixel(x + 7, y + 2, color_player_darkBlue);
	tft.drawFastHLine(x + 9, y + 3, 2, color_player_darkBlue);
	tft.drawFastHLine(x + 8, y + 1, 3, color_player_highlightBlue);
	tft.drawFastVLine(x + 11, y + 2, 2, color_player_highlightBlue);
	// right arm
	tft.fillRect(x + 8, y + 13, 3, 4, color_player_lightBlue);
	tft.drawFastVLine(x + 7, y + 13, 4, color_player_darkBlue);
	tft.drawFastHLine(x + 8, y + 17, 3, color_player_darkBlue);
	tft.drawFastHLine(x + 8, y + 15, 3, color_player_darkBlue);
	tft.drawPixel(x + 11, y + 16, color_player_darkBlue);
	tft.drawFastVLine(x + 11, y + 13, 3, color_player_highlightBlue);
	// right shoe
	tft.drawPixel(x + 13, y + 5, color_player_darkShoe1);
	tft.drawFastVLine(x + 14, y + 6, 2, color_player_darkShoe1);
	tft.drawPixel(x + 13, y + 6, color_player_lightShoe1);
	// left shoe
	tft.drawPixel(x + 13, y + 11, color_player_darkShoe1);
	tft.drawFastVLine(x + 14, y + 12, 2, color_player_darkShoe1);
	tft.drawFastHLine(x + 12, y + 13, 2, color_player_darkShoe1);
	tft.drawFastHLine(x + 12, y + 12, 2, color_player_lightShoe1);
}

void Player::SpawnPlayer()
{
}

void Player::Move(uint8_t _direction)
{
	_delay_ms(10);
	if (playerMayMove) {
		playerMayMove = false;
		lastX = posX;
		lastY = posY;
		switch (_direction) {

		case 1://up
			posY--;
			playerMayMove = false;
			break;

		case 2://down
			posY++;
				playerMayMove = false;
			break;

		case 3://right
			posX++;
				playerMayMove = false;
			break;
		case 4://left
			posX--;
				playerMayMove = false;
			break;
		}

		if (level->CheckCollision(posX, posY)) // Checkt voor collision in level
		{
			posX = lastX;
			posY = lastY;
			playerMayMove = true;
		}else {
			playerDrawDirection = _direction;
			level->DrawLevel();
			Draw(*level->tft, level->location(posX), level->location(posY));
		}

		_delay_ms(300);
		playerMayMove = true;
	}


}

void Player::SetCurrentLocation(uint8_t x, uint8_t y)
{
}

void Player::BombDropCheck()
{
	if (canDropBomb) {
		level->AddBomb(posX, posY);
		canDropBomb = false;
	}
}
