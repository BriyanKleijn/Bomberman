#include "Input.h"
#include "Nunchuk.h"

void Input::start()
{
		nunchuk_init_power(); // A1 and A2 is power supply
		nunchuk_init();
}

void Input::loop()
{
	if (nunchuk_read()) {
		if (!nunchuk_buttonC()) {
			// Draw player
			_delay_ms(10);// Anders leest die te snel de input
			ReadInput();
		}
		else {
			player->BombDropCheck();
		}
	}
}

void Input::ReadInput()
{
	if(canMove()){
		if(player->playerMayMove){

			if (threshold < nunchuk_joystickX()) {         // right
					player->Move(3);
			}else if (-threshold > nunchuk_joystickX()) {        // left
					player->Move(4);
			}else if (-threshold > nunchuk_joystickY()) {        // down
					player->Move(2);
			}else if (threshold < nunchuk_joystickY()) {         // up
					player->Move(1);
			}
		}
  }
}

// Checkt of de er input is
bool Input::canMove()
{
	if(threshold > nunchuk_joystickX() && -threshold < nunchuk_joystickX() && -threshold < nunchuk_joystickY() && threshold > nunchuk_joystickY()){
		return false;
	}
	else {
		return true;
	}
}
