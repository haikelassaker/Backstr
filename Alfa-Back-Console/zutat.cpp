#include"stdafx.h"
#include "zutat.h"

using namespace std;

zutat::zutat(string zutatName, double zutatMenge, string zutatEinheit)
{
	name = zutatName;
	menge = zutatMenge;
	masseinheit = zutatEinheit;
}

zutat::zutat(string commaString)
{
    vector<string> daZutat = werkzeuge::split(commaString, ',');
    name = daZutat[0];
    menge = stod(daZutat[1]);
    masseinheit = daZutat[2];
}

string zutat::getName()
{
	return name;
}

double zutat::getMenge()
{
	return menge;
}

string zutat::getMasseinheit()
{
	return masseinheit;
}

void zutat::setMenge(double ztMenge)
{
	menge = ztMenge;
}

string zutat::toString()
{
    return string( name + "," + std::to_string(menge) + "," + masseinheit);
}

void zutat::consoleWrite()
{
    cout << toString();
}

void zutat::consoleWriteLine()
{
    cout << toString() << endl;
}

zutat::~zutat() {}
