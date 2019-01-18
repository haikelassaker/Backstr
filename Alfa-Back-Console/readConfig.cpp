#include "stdafx.h"
#include "readConfig.h"


//readConfig::readConfig() {}


int readConfig::check_error_bits(ifstream* f)
{
    int stop = false;
    if (f->eof()) {
        // End of file reached
        stop = true;
    } else if (f->bad()) {
        string msg = "Read/writing error on i/o operation";
        perror(msg.c_str());
        throw exception(msg.c_str());
    } else if (f->fail()) {
        string msg = "Logical error on i/o operation";
        perror(msg.c_str());
        throw exception(msg.c_str());
    }
    return stop;
}

rezept * readConfig::buildRezept(string line)
{
    rezept * daRezept = new rezept("Default", 100.0, "Default", "klein", 180.0, 40.0);
    vector<string> columns = werkzeuge::split(line, '\t');
    for(unsigned int i=0; i < columns.size(); i += 1)
    {
        vector<string> field = werkzeuge::split(columns[i], ':');
        if (field[0] == "teigname")
        {
            daRezept->setTeigname(field[1]);
        }
        if (field[0] == "basisAnzahl")
        {
            daRezept->setAnzahl(stod(field[1]));
        }
        if (field[0] == "form")
        {
            daRezept->setForm(field[1]);
        }
        if (field[0] == "groesse")
        {
            daRezept->setGroesse(field[1]);
        }
        if (field[0] == "backTemperatur")
        {
            daRezept->setBacktemperatur(stod(field[1]));
        }
        if (field[0] == "backZeit")
        {
            daRezept->setBackzeit(stod(field[1]));
        }
        if (field[0] == "Zutaten")
        {
            vector<string> daZutaten = werkzeuge::split(field[1], '|');
            for (unsigned int j=0; j < daZutaten.size(); j += 1)
            {
                daRezept->addZutat(new zutat(daZutaten[j]));
            }
        }
        if (field[0] == "Verzierungen")
        {
            vector<string> daZutaten = werkzeuge::split(field[1], '|');
            for (unsigned int j = 0; j < daZutaten.size(); j += 1)
            {
                daRezept->addVerzierung(new zutat(daZutaten[j]));
            }
        }
    }
    return daRezept;
}

rezept * readConfig::readRezept(string filename)
{
    rezept * daRezept = new rezept("Default", 100.0, "Default", "klein", 180.0, 40.0);
    string line;
    ifstream fs(filename);

    if(!fs.is_open())
    {
        string msg = "No such file or directory '" + filename + "'";
        throw exception(msg.c_str());
    }
    check_error_bits(&fs);
    while(1)
    {
        getline(fs, line);
        if(check_error_bits(&fs))
        {
            break;
        }
        daRezept = buildRezept(line);
    }
    fs.close();
    return daRezept;
}

readConfig::~readConfig() {}
