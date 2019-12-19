#include "Bomb.h"
#include "Player.h"
#include "GameObject.h"
#include "Level.h"
#include "Input.h"


#include <avr/io.h>
#include <avr/interrupt.h>
 uint8_t teller = 0;

volatile uint8_t ticks = 0;
Adafruit_ILI9341 tft(10,9);

Level level(tft, teller);
Player flayer(1, level);
Input input(flayer);

ISR(TIMER0_COMPA_vect)
{
	teller++;
}

int main(void)
{
	TCCR0A |= (1<<WGM01);
	TCCR0B |= (1<<CS01);

	TIMSK0 |= (1<<OCIE0A);
	OCR0A = 78;

	sei();

	tft.begin();
	tft.setRotation(1);
	tft.fillScreen(0x1212);
	level.SetLevel();
	level.DrawLevel();
	input.start();

	while (1)
	{
			level.Timer();
		input.loop();

	}
}
