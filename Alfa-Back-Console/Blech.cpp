#include "stdafx.h"
#include "Blech.h"




int Blech::getBlechAnzahl(double plaetzchenXGroesse, double plaetzchenYGroesse)
{
	double plaetzchenXGroesseMitAbstand = plaetzchenXGroesse + 40;
	double plaetzchenYGroesseMitAbstand = plaetzchenYGroesse + 40;
	int spaltenAnzahl = (int)(xGroesse / plaetzchenXGroesseMitAbstand);
	int reihenAnzahl = (int)(yGroesse/ plaetzchenYGroesseMitAbstand);
	return  spaltenAnzahl * reihenAnzahl;
	
}


