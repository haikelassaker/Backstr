#include "stdafx.h"
#include "Band.h"
#include <iostream>
#include <string>
using namespace std;

int Band::getGeschwindigkeit()
{
	return Geschwindigkeit;
}

void Band::setGeschwindigkeit(int Geschwind)
{
	Geschwindigkeit = Geschwind;
	cout << "Band::setGeschwindigkeit(int Geschwind)" << endl;

}

bool Band::GetGeschwindigkeitStatus()
{
	if (Geschwindigkeit = 0)
	{
		return false;
	}
	return true;
}

Band::Band() : Geschwindigkeit {0}
{
}


Band::~Band()
{
}
