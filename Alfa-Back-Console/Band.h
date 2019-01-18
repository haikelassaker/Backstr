#pragma once
#include "BandSteuerung.h"

class Band : public BandSteuerung
{
	int Geschwindigkeit;
public:
	int getGeschwindigkeit();
	void setGeschwindigkeit(int Geschwind);
	bool GetGeschwindigkeitStatus();
	Band();
	~Band();
};

