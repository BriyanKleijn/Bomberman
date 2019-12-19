#ifndef _STARTSCHERMH_
#define _STARTSCHERMH_
#pragma once
#include "Scherm.h"
class Startscherm:public Scherm
{
public:
	Startscherm(Adafruit_ILI9341 &_tft) :Scherm(_tft) {}

private:
	void StartLobby();
	void Options();
	void SearchLobby();
};
#endif