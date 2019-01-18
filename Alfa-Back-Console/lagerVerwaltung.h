#pragma once
#include <vector>
#include <string>
#include <map>
#include "zutat.h"
#include "rezept.h"
using namespace std;
class lagerVerwaltung
{
private:
	/// eine map zur Lagerhaltung von zutaten mit Initialisierte werte
    map<string, zutat*> lagerBestandZt;
    /// eine map zur Lagerhaltung von Verzierungen mit Initialisierungswerte
    map<string, zutat*> lagerBestandVezgen;

    void fillLager() {
        lagerBestandZt.insert(pair<string, zutat*>("Backpulver", new zutat("Backpulver", 1000.0, "g")));
        lagerBestandZt.insert(pair<string, zutat*>("Eier", new zutat("Eier", 1000, "l")));
        lagerBestandZt.insert(pair<string, zutat*>("Mehl", new zutat("Mehl", 50000, "g")));
        lagerBestandZt.insert(pair<string, zutat*>("Milch", new zutat("Milch", 100, "l")));
        lagerBestandZt.insert(pair<string, zutat*>("Pflanzenfett", new zutat("Pflanzenfett", 500, "l")));
        lagerBestandZt.insert(pair<string, zutat*>("Zitronenpulver", new zutat("Zitronenpulver", 10000, "g")));
        lagerBestandZt.insert(pair<string, zutat*>("Rum", new zutat("Rum", 100, "l")));
        lagerBestandZt.insert(pair<string, zutat*>("Vanillinzucker", new zutat("Vanillinzucker",10000, "g")));
        lagerBestandZt.insert(pair<string, zutat*>("Kakao", new zutat("Kakao", 10000, "g")));
	
		lagerBestandZt.insert(pair<string, zutat*>("Zucker", new zutat("Zucker", 10000, "g")));

        lagerBestandVezgen.insert(pair<string, zutat*>("Kakaoguss", new zutat("Kakaoguss", 100, "l")));
        lagerBestandVezgen.insert(pair<string, zutat*>("Schokostreusel", new zutat("Schokostreusel", 10000, "g")));
        lagerBestandVezgen.insert(pair<string, zutat*>("Zuckerstreusel(bunt)",new zutat("Zuckerstreusel(bunt)", 10000, "g")));
        lagerBestandVezgen.insert(pair<string, zutat*>("Zitronenguss", new zutat("Zitronenguss", 100, "l")));
        lagerBestandVezgen.insert(pair<string, zutat*>("Zimt", new zutat("Zimt", 10000, "g")));
        lagerBestandVezgen.insert(pair<string, zutat*>("Zitronenpulver",new zutat("Zitronenpulver", 10000, "g")));
        lagerBestandVezgen.insert(pair<string, zutat*>("Kakaoguss", new zutat("Kakaoguss", 100, "l")));
        lagerBestandVezgen.insert(pair<string, zutat*>("Vanillinzucker", new zutat("Vanillinzucker",10000, "g")));
        lagerBestandVezgen.insert(pair<string, zutat*>("Mandeln", new zutat("Mandeln", 30000, "g")));
        lagerBestandVezgen.insert(pair<string, zutat*>("Marmelade", new zutat("Marmelade", 10, "l")));
        lagerBestandVezgen.insert(pair<string, zutat*>("Walnuesse", new zutat("Walnuesse", 10000, "g")));
        lagerBestandVezgen.insert(pair<string, zutat*>("Haselnuesse", new zutat("Haselnuesse", 10000, "g")));        
    }
	///sagt aus, ob die fuer die Bestellung genug ware ist  
	bool lagerZustand;

public:
	/**
	 * Registrierung von Eingang von Zutaten im Lageverwaltung 
	 */
	void setEingangwareVerzierungen(zutat* lagerBestandVerzierungen);

	/**
	 * Registrierung von Eingang von Zutaten im Lageverwaltung
	 */
	void setEinganswareZutaten(zutat* lagerBestandVerzierungen);

	/**
	 * Bestellmenge an Zutaten und Verzierungen mit Lagerzustand vergleichen
	 * @Parameter zutatMenge
	 * @Parameter verzierungMenge
	 */
	bool pruefeLageBestand(map<string, zutat*> zutatMenge, map<string, zutat*> verzierungMenge);
	/**
	*Bestellung an Zutaten und Verzierungen von der Lagerbestand abziehen
	*@ Parameter zutatMenge
	*@ Parameter verzierungMenge
	*/
	void bestellMengeAbziehenLage(map<string, zutat*> zutatMenge, map<string, zutat*> verzierungMenge);
	/**
	* gibt die boolesche Variable lageZustand zurück.
	*/
	bool getLagerzustand();
	/**
	* lagerbestand anzeigen lassen
	*/
	void lagerBestandAnzeigen();
	/**
	 * @Constructor
	 * mit zwei maps zur Lagerverawltung lagerBestandZutaten und lagerBestandVerzierungen
	 */
	lagerVerwaltung(map<string, zutat*> lagerBestandZutaten, map<string, zutat*> lagerBestandVerzierungen);

    /** @constructor */
	lagerVerwaltung();
};