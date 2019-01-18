#pragma once
#include "AutomatSteuerung.h"


class OfenSteuerung : public AutomatSteuerung
{
	AutomatSteuerung * AutomatSteuerungOfenSteuerung;
public:
	void setAutomatSteuerungPointer(AutomatSteuerung *  ASATM);

	void OfenAufheizen();
	bool OfenTemperaturStatus();
	OfenSteuerung();
	~OfenSteuerung();
};

