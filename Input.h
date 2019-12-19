#ifndef _INPUTH_
#define _INPUTH_
#pragma once

#define threshold 40
#include "Player.h"

class Input
{
public:
	Player* player;
	Input(){}
	Input(Player &fl){
		player = &fl;
	}

	void start();
	void loop();
private:
	void ReadInput();
	bool canMove();
};
#endif
