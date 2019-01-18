#include "stdafx.h"
#include "Ofen.h"
#include <iostream>
#include <string>
using namespace std;


double Ofen::getTemperatur()
{
	
	//cout << "Ofen::getTemperatur(int Temperatur) - " << Temperatur << endl;
	return Temperatur;

}

void Ofen::setTemperatur(int TemperaturIN)
{
	Temperatur = TemperaturIN;
	cout << "Ofen::setTemperatur(int Temperatur) - " << Temperatur << endl;
}

Ofen::Ofen() : Temperatur{ 0 }
{
}


Ofen::~Ofen()
{
}
