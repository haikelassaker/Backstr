#include "stdafx.h"
#include "OfenSteuerung.h"
#include "Ofen.h"
#include <iostream>
#include <string>
using namespace std;


void OfenSteuerung::setAutomatSteuerungPointer(AutomatSteuerung * ASATM)
{

	AutomatSteuerungOfenSteuerung = ASATM;

}

void OfenSteuerung::OfenAufheizen()
{
}

bool OfenSteuerung::OfenTemperaturStatus()
{
	double Temperat;
	Ofen * Ofen1;
	Ofen1 = AutomatSteuerungOfenSteuerung->getOfen();
	Temperat = Ofen1->getTemperatur();
	cout << "bool OfenSteuerung::OfenTemperaturStatus() - " << Temperat << "C" << endl;
	
	if (Temperat == 0)
	{
		return false;
	}
	else 
	{ 
	return true;
	}
}

OfenSteuerung::OfenSteuerung()
{
}


OfenSteuerung::~OfenSteuerung()
{
}
