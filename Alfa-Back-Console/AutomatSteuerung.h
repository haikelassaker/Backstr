#pragma once

/*
#include <iostream>
#include "Ofen.h"
#include "ParameterListe.h"
#include "AusnahmenUndThreadsMon.h"
#include "Band.h"
#include "OfenSteuerung.h"
*/
#include "lagerVerwaltung.h"
#include "rezept.h"



class AutomatSteuerung;
class Ofen;
class Band;
class AusnahmenUndThreadsMon;
class ParameterListe;
class OfenSteuerung;
class lagerVerwaltung;
class rezept;

class AutomatSteuerung
{
	bool BackProzessTimerStatus = false; // 1 Prozess Lock

	Ofen * Ofn;
	Band * Bnd;
	AusnahmenUndThreadsMon * AM;
	ParameterListe * PL;
	OfenSteuerung * OfnSu;

	rezept* rezepteinlesen;
	lagerVerwaltung * lgVerwaltung;

	int JobQueueStatus;
	int blechAnzahl;
public:
	void SetrezeptRrezepteinlesen(rezept* rezepteinlesen1);
	void SetlagerVerwaltunglgVerwaltung(lagerVerwaltung * lgVerwaltung1);
	rezept * GetrezeptRrezepteinlesen();
	lagerVerwaltung * GetlagerVerwaltunglgVerwaltung();


	void plaetzchenAnzahlErmitteln();
	void blechAnzahlErmitteln(double plaetzchenAnzahl, double plaetzchenAnzahlProBlech);
	int getblechAnzahl();
	void blechBelegen();
	void Backen(int);
	int AbkuehlenVerzierungen(int BackZeitIn);
	double VerweilDauerBestimmen(double geschwindigkeit);
	void InitClassen(AutomatSteuerung * As);
	void InitDelete(AutomatSteuerung * As);
	Ofen *  getOfen();
	Band * getBand();
	AusnahmenUndThreadsMon * getAusnahmenUndThreadsMon();
	ParameterListe * getParameterListe();
	OfenSteuerung * getOfenSteuerung();

	void setOfen(Ofen * Ofn1);
	void setBand(Band * Bnd1);
	void setAusnahmenUndThreadsMon(AusnahmenUndThreadsMon * ATM1);
	void setParameterListe(ParameterListe * PL1);
	void setOfenSteuerung(OfenSteuerung * setOfSteu1);
	

	int GetJobQueueStatus();
	void SetJobQueueStatus(int Status);

	AutomatSteuerung();
	~AutomatSteuerung();
};