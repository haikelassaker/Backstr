#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "werkzeuge.h"

using namespace std;

class zutat
{	
private:
    /** Name der Zutat*/
    string name;

	/** Menge der Zutat*/
	double menge;

    /** Masseinheit der zutat g, Kg, l , ml, etc. */
	string masseinheit;

public:
	/**
	 * @constructor
	 * @param zutatName Name der Zutat
	 * @param zutatMenge Menge der Zutat
	 * @param zutatEinheit Masseinheit der Zutat
	 */
	zutat(string zutatName, double zutatMenge, string zutatEinheit);

    /**
     * @constructor
     * @param commaString Komma getrennte Zeichenkette der Zutat
     * @example Milch,1,l
     */
    zutat(string commaString);

	/** Getter Name */
	string getName();

	/** Getter Menge */
	double getMenge();

	/** Getter Masseinheit */
	string getMasseinheit();

	/** Setter Menge */
	void setMenge(double ztMenge);

    /**
     * Gibt die Zutat als Comma-Seperated-String zurueck
     */
    string toString();

    /**
    * Schreibt Zutat als Comma-Seperated-String auf die Console
    */
    void consoleWrite();

    /**
     * Schreibt Zutat als Comma-Seperated-Zeile auf Console
     */
    void consoleWriteLine();

    /** @destructor */
	~zutat();
};
