#pragma once
#include <vector>
#include <map>
#include "werkzeuge.h"
#include "zutat.h"

using namespace std;

/**
* Klasse Rezept um Teig- und Verzierungszusammensetzung  von der Konfiguration zu speichern
*/
class rezept
{
private:
	
	
	/**
	* Key: Zutatenname, Value: Instanz der Klasse Zutat fuer Basisanzahl
	* von Keksen
	*/
	map <string, zutat*>  zutaten;

	/**
	* Key: Verzierungszutatenname, Value: Anzahl Einheiten benoetigt fuer
	* Basisanzahl
	* von Keksen
	*/
	map <string, zutat*>  verzierungen;

	/** Name fuer Teig */
	string tgName;

	/** Kantenlaenge x fuer Rechteck in das die Form eingepasst wird */
	double xBetrag;

	/**Anzahl der Plaetzchen*/
	double basisAnzahlPlaetzchen;

	/** form der Plaetzchen*/
	string plaetzchenForm;

	/** Kantenlaenge y fuer Rechteck in das die Form eingepasst wird */
	double yBetrag;

	/** Die Temperatur für backen in °C*/
	double backTemp;

	/** Die Backzeit in Minuten*/
	double backZt;

	/** plaetzchen Groesse: gross, mittel, klein*/
	string plaetzchenGroesse;

    /** priv @Constructor */
    rezept();
public:
	/**
	 * Properties der Klasse setzen
	 * @construktor
	 * @param teigName Teigname
	 * @param pleatzchenAnzahl Anzahl an Keksen die beim Grundrezept gestanzt werden koennen
	 * @param form Form des Plaetzchens
	 * @param xGroesse Kantenlaenge x
	 * @param yGroesse Kantenlaenge Y
	 * @param backTemperatur Backtemperatur
	 * @param backZeit Backzeit
	 */
	rezept(string teigName, double pleatzchenAnzahl, string form, string groesse, double backTemperatur, double backZeit);

	/**
	 * Fuegt eine Zutat mit Mengenangabe zur Zutatenliste hinzu
	 * @param name Name der Zutat
	 * @param einheiten Anzahl der Einheiten, die fuer Rezept benoetigt werden
	 */
	void addZutat(zutat* ingredient);

	/**
	 * Fuegt eine Verzierungszutat mit Mengenangabe zur Verzierungszutatenliste
	 * hinzu
	 * @param name Name der Zutat
	 * @param einheiten Anzahl der Einheiten, die fuer Rezept benoetigt werden
     */
	void addVerzierung(zutat* ingredient);

	/**
	 * lese die Menge der Zutaten ab
	 * @param map zutaten, der die menge beeinhaltet
	 */
	map<string,zutat*>  getZutatMenge();

	/**
	 * lese die Menge der Zutaten ab
	 * @param map verzeirungen, die die menge beeinhaltet
	 */
	map<string, zutat*> getVerzierungsMenge();

	/**
	* Gibt Name der Teigsorte zurück 
	* @return Name
	*/
	string getTeigName();

	/**
	 * Gibt Basis Anzahl der Plaetzchen 
	 * @return Stueckzahl des Rezeptes
	 */
	double getBasisPlaetzchenAnzahl();
	/**
	 * Gibt die Groesse der Plaetzchen als string
     * @example gross, mittel oder klein
	 */
	string getPlaetzchenGroesse();

	/**
	 * Gibt Form der Plaetzechen zurück
	 * @example Stern, Oval, Kreis, Quadrat, Rechteck, Dreieck
	 */
	string getForm();

	/**
 	 * Gibt die Breite  der Plaetzchen zurück
     * @parameter groesse Gross, mittel oder klein
     */
	double getXBetrag(string groesse);

	/**
     * Gibt Höhe der Plaetzchen in abheangigkeit der Groesse zurück
     * @parameter groesse gross, mittel oder klein
	 */
	double getYBetrag(string groesse);

	/**
	 * Gibt die Backtemperatur in abheangigkeit der Groesse zurück
     */
	double getBackTemperatur();

	/**
	 * Gibt die Backzeit zurück
     */
	double getBackZeit();

    /**
     * Veraltet wird entfernt.
     */
    rezept* getKonfigdatei();
    
    /**
     * Gibt das Rezept als datenzeilen-string zurueck
     * @returns serialisierter String der Rezept-Klasse
     */
    string toString();

    // Setter
    void setTeigname(string tn);
    void setAnzahl(double anz);
    void setForm(string frm);
    void setGroesse(string gr);
    void setBacktemperatur(double temp);
    void setBackzeit(double zeit);

    string getZutatenWriteStr();
    string getVerzierungenWriteStr();

	~rezept();
};