#pragma once
#include "AutomatSteuerung.h"
#include "rezept.h"

class Blech : public AutomatSteuerung
{
 const	double xGroesse=400;
 const	double yGroesse = 600;
 
public:
	int getBlechAnzahl(double plaetzchenXGroesse,double plaetzchen);
	
};

