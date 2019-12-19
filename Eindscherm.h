#ifndef _EINDSCHERMH_
#define _EINDSCHERMH_
#include "Scherm.h"
#pragma once
class Eindscherm :public Scherm
{
public:
Eindscherm(Adafruit_ILI9341 &_tft) : Scherm(_tft) {}
uint8_t setHighscore();
};
#endif