#include "stdafx.h"
#include "lagerVerwaltung.h"
#include <iostream>

using namespace std;

void lagerVerwaltung::setEingangwareVerzierungen(zutat* eingangswareVerzierungen)
{
	lagerBestandVezgen.insert(pair<string, zutat*>(eingangswareVerzierungen->getName(), eingangswareVerzierungen));
}

void lagerVerwaltung::setEinganswareZutaten(zutat* eingangswareZutaten)
{
	lagerBestandZt.insert(pair<string, zutat*>(eingangswareZutaten->getName(), eingangswareZutaten));
}

bool lagerVerwaltung::pruefeLageBestand(map<string,zutat*> zutatMenge, map<string, zutat*> verzierungMenge)
{
	bool lageZustandZutat{ true }, lageZustandVerzierungen{ true };
	/// Schleife zu ueberpruefen von Verfuegbarkeit des Zutaten Bestandes
	for (map<string, zutat*>::iterator it = zutatMenge.begin(); it != zutatMenge.end(); it++)
	{
		
		string name = it->second->getName();
		double  menge, diff;
		map<string,zutat*>::iterator it_lagerIteraror=lagerBestandZt.find(name);
		if (it_lagerIteraror != lagerBestandZt.end())
		{
			menge=it_lagerIteraror->second->getMenge();
			if (it->second->getMenge() <= menge)
			{

				continue;
			}
			else
			{
				diff = (it->second->getMenge() - menge);
				lageZustandZutat = false;
				cout << " Nicht genug " << name << ", in der lager ist. " << endl << endl;
				cout << "Ein mindest Menge an " << name << " von " <<diff<<" bestellen. "<< endl << endl;
			}

		}
		else
		{
			cout << "Der Zutat: " <<name<<" ist nicht in der Lager  vorhanden!!"<< endl;
			
			lagerBestandZt.insert(pair<string, zutat*>(name, new zutat(name, 0, "")));
			lageZustandZutat = false;
			break;
		}
	}
	
	/// Schleife zu ueberpruefen von Verfuegbarkeit der Verzierungen Bestandes
	for (map<string, zutat*>::iterator it = verzierungMenge.begin(); it != verzierungMenge.end(); it++)
	{
		string name = it->second->getName();
		
		double  menge;
		map<string, zutat*>::iterator it_lager = lagerBestandVezgen.find(name);
		if(it_lager!=lagerBestandVezgen.end())
		{ 
		menge=it_lager->second->getMenge();
			if(menge >= (it->second)->getMenge())
			{
			continue;
			}else
			{
			double	diff = (it->second->getMenge() - menge);
			lageZustandVerzierungen = false;
			cout << " Nicht genug  " << name << ", in der lager ist. " << endl << endl;
			cout << "Ein mindest Menge an " << name << " von " << diff << " bestellen. " << endl << endl;
			}
		}else
		{
			cout << "Verzierung  " << name << " ist nicht in der Lager  vorhanden!!" << endl;
			lagerBestandVezgen.insert(pair<string, zutat*>(name, new zutat(name, 0, "")));
			lageZustandVerzierungen = false;
			break;
		}
	}
	lagerZustand = (lageZustandZutat&lageZustandVerzierungen);
	return lagerZustand;
}
//Bestellmenge von der Lage abziehen, falls genug ware da ist.
void lagerVerwaltung::bestellMengeAbziehenLage(map<string, zutat*> zutatMenge, map<string, zutat*> verzierungMenge)
{
	bool pruefe = pruefeLageBestand(zutatMenge, verzierungMenge);
	if(pruefe)
	{
	for (map<string, zutat*>::iterator it = zutatMenge.begin(); it != zutatMenge.end(); it++)
	{
		string name = it->second->getName();
		double menge = lagerBestandZt.find(name)->second->getMenge();
		lagerBestandZt[name]->setMenge((menge - (it->second->getMenge())));
	}
	for (map<string, zutat*>::iterator it = verzierungMenge.begin(); it != verzierungMenge.end(); it++)
	{
		string name = it->second->getName();
		double menge = lagerBestandVezgen.find(name)->second->getMenge();
		lagerBestandVezgen[name]->setMenge((menge - (it->second->getMenge())));
	}
	}
	else
	{
		cout<<" nicht genug Ware in der Lage bitte nach bestellen!!"<<endl; 
	}
}

bool lagerVerwaltung::getLagerzustand()
{
	return lagerZustand;
}

void lagerVerwaltung::lagerBestandAnzeigen()
{
	for (map<string, zutat*>::iterator it = lagerBestandZt.begin(); it != lagerBestandZt.end(); it++)
	{
		cout << "Aktuell Menge an Zutaten: " << (it->second)->getName() << " ist " << (it->second)->getMenge() << endl;
	}
	for (map<string, zutat*>::iterator it = lagerBestandVezgen.begin(); it != lagerBestandVezgen.end(); it++)
	{
		cout << "Aktuelle Menge an Verzierungen: " << (it->second)->getName() << " ist " << (it->second)->getMenge() << endl;
	}
}

lagerVerwaltung::lagerVerwaltung(map<string, zutat*> lagerBestandZutaten, map<string, zutat*> lagerBestandVerzierungen)
{
    lagerBestandZt = lagerBestandZutaten;
    lagerBestandVezgen = lagerBestandVerzierungen;
}

lagerVerwaltung::lagerVerwaltung()
{
    fillLager();
}


