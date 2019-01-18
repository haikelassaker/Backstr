#pragma once
#include <string>
#include <vector>

using namespace std;

class werkzeuge
{
private:
    werkzeuge();
public:
    /**
    * Zerschneided den String s mit dem Trennzeichen c
    * source http://www.cplusplus.com/articles/2wA0RXSz/
    * @param s String der zerschnitten werden soll
    * @param c Trennzeichen
    * @returns Vector mit den Teilstuecken von s
    */
    static const vector<string> split(const string& s, const char& c);


    /**
    * Gibt einen string zureuck, der aus den Elmenten von v mit Hilfe des delimiters
    * verbunden wird
    * source: https://stackoverflow.com/a/40497964/1553261
    * @param v vector<string> der mit delimiter verbunden werden soll
    * @param delimiter "Kleber" der einzelnen string Elemente verbindet
    */
    static string join(const string & delimiter, const vector<string> & v);

    ~werkzeuge();
};

