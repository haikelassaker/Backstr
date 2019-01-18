#pragma once
#include "AutomatSteuerung.h"


class BandSteuerung : public AutomatSteuerung
{

public:
	void GeschwindigkeitRegeln();
	BandSteuerung();
	~BandSteuerung();
};

