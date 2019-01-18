#include "stdafx.h"
#include "ParameterListe.h"
#include "Ofen.h"
#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <shlwapi.h>
#include <algorithm>
#include <thread>
#include <chrono>
#include <iostream>
#include <functional>
#include <string>
#include <mutex>
using namespace std;

//rezept * rezepteinlesen3 = AutomatSteuerungParameterListe->GetrezeptRrezepteinlesen();
//rezepteinlesen3->
//return Bestand;

ParameterListe::ParameterListe()
{
}


ParameterListe::~ParameterListe()
{
}

void ParameterListe::setAutomatSteuerungPointer(AutomatSteuerung * ASPM)
{
	AutomatSteuerungParameterListe = ASPM;
}

bool ParameterListe::ZutatenPruefen()//map <string,zutat>
{
	lagerVerwaltung * lgVerwaltung3 = AutomatSteuerungParameterListe->GetlagerVerwaltunglgVerwaltung();
	bool Bestand = lgVerwaltung3->getLagerzustand();
	//std::cout << Bestand << "- bool Bestand = lgVerwaltung3->getLagerzustand(); " << endl;
	SetSetZutatenTrueFalse(Bestand);
	//return Bestand;
	return true;
}

bool ParameterListe::TeigPruefen()
{
	string s;
	rezept * rezepteinlesen3 = AutomatSteuerungParameterListe->GetrezeptRrezepteinlesen();
	s = rezepteinlesen3->getTeigName();

	if (s.empty() != 0)
	{
		SetTeigTrueFalse(true);
		return true;
	}
	else
	{
		SetTeigTrueFalse(false);
		return false;
	}
}

bool ParameterListe::FormPruefen()
{
	string s;
	rezept * rezepteinlesen3 = AutomatSteuerungParameterListe->GetrezeptRrezepteinlesen();
	s = rezepteinlesen3->getForm();
	if (s.empty() != 0)
	{
		SetFormTrueFalse(true);
		return true;
	}
	else
	{
		SetFormTrueFalse(false);
		return false;
	}
}

bool ParameterListe::ConfigPruefen()
{
	return false;
}
/*
bool ParameterListe::Teigroesse()
{
	double x;
	double y;
	rezept * rezepteinlesen3 = AutomatSteuerungParameterListe->GetrezeptRrezepteinlesen();
	//x = rezepteinlesen3->getXBetrag();

	/*
	if ((x != 0) && (y != 0))
	{
		SetTeigroesseTrueFalse(true);
		return true;
	}
	else
	{
		SetTeigroesseTrueFalse(false);
		return false;
	}
	
	return false;
}
*/

/*
bool ParameterListe::BlechAusfuelungPruefen()
{
	double PlaetzchenAnzahl;

	rezept * rezepteinlesen3 = AutomatSteuerungParameterListe->GetrezeptRrezepteinlesen();
	rezepteinlesen3->getBasisPlaetzchenAnzahl();
	//rezepteinlesen3.pla

	//AutomatSteuerungParameterListe->blechAnzahlErmitteln(PlaetzchenAnzahl, );

	//blechAnzahlErmitteln(double plaetzchenAnzahl, double plaetzchenAnzahlProBlech)

	return false;
}
*/

bool ParameterListe::BackzeitPruefen()
{

	//AutomatSteuerungParameterListe->VerweilDauerBestimmen();
	return false;
}

bool ParameterListe::TemperaturPruefen()
{
	int getBackTemperatur;
	int getAktuellTemperatur;

	rezept * rezepteinlesen3 = AutomatSteuerungParameterListe->GetrezeptRrezepteinlesen();
	getBackTemperatur = (int)rezepteinlesen3->getBackTemperatur();

	Ofen * Ofen4;
	Ofen4 = AutomatSteuerungParameterListe->getOfen();
	getAktuellTemperatur = (int)Ofen4->getTemperatur();

	if (getBackTemperatur = getAktuellTemperatur)
	{
		SetTemperaturTrueFalse(true);
		return true;
	}
	else
	{
		SetTemperaturTrueFalse(false);
		return false;
	}
}

bool ParameterListe::ZusammenfassungFunc()
{
	/*
	std::mutex mu;
	mu.lock();*/
	//
	vector<bool> VectroBool(MaxEnumErrorSIZE, true);
	vector<bool>::iterator ITERator;
	size_t Hashret = 0;
	size_t HashGruensize_t;
	string HashGruen;

	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	/*
	ZutatenPruefen();
	TeigPruefen();
	FormPruefen();
	ConfigPruefen();
	*/
	//Teigroesse();
//	BlechAusfuelungPruefen();
	/*
	BackzeitPruefen();
	TemperaturPruefen();
	*/
	TemperaturPruefen();

	HashGruensize_t = std::hash<std::vector<bool>>()(VectroBool);
	HashGruen = std::to_string(HashGruensize_t);

	PL1->HashGruenSave = HashGruensize_t;


	// exceptions
	TryCatchLoop("An exception occurred. Exception ZutatenBool - ", "ZutatenBool", Zutaten, PL1->my_Param.ZutatenBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception TeigBool  - ", "TeigBool", Teig, PL1->my_Param.TeigBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception FormBool  - ", "FormBool", Form, PL1->my_Param.FormBool, VectroBool);
	// exceptions
	//TryCatchLoop("An exception occurred. Exception TeigGroesseBool - ", "TeigGroesseBool", TeigGroesse, PL1->my_Param.TeigGroesseBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception ConfigFileBool - ", "ConfigFileBool", ConfigFile, PL1->my_Param.ConfigFileBool, VectroBool);
	// exceptions
	//TryCatchLoop("An exception occurred. Exception BlechAusFuellungBool - ", "BlechAusFuellungBool", BlechAusFuellung, PL1->my_Param.BlechAusFuellungBool, VectroBool);

	TryCatchLoop("An exception occurred. Exception BackzeitBool - ", "BackzeitBool", BackzeitEnum, PL1->my_Param.BackzeitBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception TemperaturBool - ", "TemperaturBool", TemperaturBoolEnum, PL1->my_Param.TemperaturBool, VectroBool);

	//Pruefe BOOL Vector fuer ZusammenfassungBool

	Hashret = std::hash<std::vector<bool>>()(VectroBool);

	//std::cout << endl << "Exception Matrix Hashret is : " << Hashret << endl;
	//std::cout << "HashGruen is : " << HashGruen << endl;
	string Hash_str = std::to_string(Hashret);

	if ((PL1->HashretSave) != Hashret) // keine Status-Veraenderung 
	{
		//cout << "HashretSave -  " << PL1->HashretSave << endl;
		//cout << "Hash_str -  " << Hashret << endl;
		PL1->HashretSave = Hashret;
	//cout << "Exception Matrix Hash_str -  " << Hash_str << endl;

	if (HashGruen.compare(Hash_str) != 0)
	{
		std::cout << HashGruen << "- Hash - Alles ist gut - ist nicht gleich zu Error Matrix Hash : " << Hash_str << endl;
		PL1->my_Param2.ZusammenfassungBool = false;
	}
	else
	{
		PL1->my_Param2.ZusammenfassungBool = true;
	}

	// exceptions
	int ITERatorLoopRetStatus = TryCatchLoop("Exception Matrix erstellt - mehrere Ausnahmen sind aufgetreten - ", "ZusammenfassungBool", (-1), PL1->my_Param2.ZusammenfassungBool, VectroBool, ITERator );

	}

	return PL1->my_Param2.ZusammenfassungBool;
	
	//mu.unlock();
}


int ParameterListe::GetErrorListe()
{

	return 0;
}

int ParameterListe::SetSetZutatenTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.ZutatenBool = TrueFalse;
	return 0;
}

int ParameterListe::SetTeigTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.TeigBool = TrueFalse;
	return 0;
}

int ParameterListe::SetFormTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.FormBool = TrueFalse;
	return 0;
}

int ParameterListe::SetConfigTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.ConfigFileBool = TrueFalse;
	return 0;
}

/*
int ParameterListe::SetTeigroesseTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.TeigGroesseBool = TrueFalse;
	return 0;
}
*/

/*
int ParameterListe::SetBlechAusfuelungTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.BlechAusFuellungBool = TrueFalse;
	return 0;
}
*/

int ParameterListe::SetBackzeitTrueFalse(bool TrueFalse)
{
	ParameterListe * PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.BackzeitBool = TrueFalse;
	return 0;
	return 0;
}

int ParameterListe::SetTemperaturTrueFalse(bool TrueFalse)
{
	ParameterListe * PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.TemperaturBool = TrueFalse;
	return 0;
}


int ParameterListe::SetZusammenfassungFuncTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param2.ZusammenfassungBool = TrueFalse;
	return 0;
}



int ParameterListe::TryCatchLoop(string ExceptMessageS, string CoutMessages, int ErrorNumber, bool FlagTest, vector<bool>& VectorBoolPL)
{
	try
	{
		bool i = true;
		int n = 0;
		i = FlagTest;

		//std::cout << "*FlagTest : " << FlagTest << endl;

		if (i == false)
		{
			VectorBoolPL.at(ErrorNumber).flip();
			throw ErrorNumber;
		}
		else if (i == true)
		{
			//std::cout << CoutMessages << " is 1" << endl;
		}

	}
	catch (int e) //e -ErrorNumber
	{
		//cout << ExceptMessageS << e << endl << endl;
		int Error = e;
	}

	return 0;
}

int ParameterListe::TryCatchLoop(string ExceptMessageS, string CoutMessages, int ErrorNumber, bool FlagTest, vector<bool>& VectorBoolPL, vector<bool>::iterator ITERator )
{
	try
	{
		bool i = true;
		int n = 0;
		i = FlagTest;

		if (i == false)
		{
			throw ErrorNumber;
		}
		else if (i == true)
		{
			//std::cout << CoutMessages << " is 1" << endl;
		}

	}
	catch (int e)
	{
		//cout << ExceptMessageS << e << endl;
        if(e) 
        {
            cout << "Rückmeldung einer real existierenden Maschine - Exception Matrix :" << endl;
        }
		for (ITERator = VectorBoolPL.begin(); ITERator != VectorBoolPL.end(); ITERator++)
		{
			cout << *ITERator;
		}
		cout << endl << endl;
        
		cout << "Matrix:\n 1.Zutaten,\n 2.Teig,\n 3.Form,\n 4.ConfigFile,\n 5.BackzeitEnum,\n 6.TemperaturBoolEnum" << endl;
		cout << "_____________________" << endl << endl;
		return false;
	}


	return true;

}