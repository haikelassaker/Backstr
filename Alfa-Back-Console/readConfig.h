#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "werkzeuge.h"
#include "zutat.h"
#include "rezept.h"


using namespace std;

class readConfig
{
private:
    /**
     * Handles Error-Bits from Filestream
     * Based on https://gehrcke.de/2011/06/reading-files-in-c-using-ifstream-dealing-correctly-with-badbit-failbit-eofbit-and-perror/
     */
    static int check_error_bits(ifstream * f);
    /**
    * @constructor
    */
    //readConfig();
public:
    /**
     * Versucht Filename einzulesen
     * @Returns rezept
     * @throws excption
     */
    static rezept * readRezept(string filename);

    /**
     * Erstellt ein Rezept aus einer Zeile text-input
     * @param line Zeile mit den serialisierten Rezeptdaten
     * @throws exception
     */
    static rezept * buildRezept(string line);

    /**
     * @destructor
     */
    ~readConfig();
};
