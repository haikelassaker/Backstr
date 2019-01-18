#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
#include "AutomatSteuerung.h"
using namespace std;


class ParameterListe : public AutomatSteuerung // Status 3
{

	AutomatSteuerung * AutomatSteuerungParameterListe;

/*
	struct Param
	{
		bool ZutatenBool = false;
		bool VerzierungBool = true;
		bool TeigBool = true;
		bool FormBool = false;
		bool TeigGroesseBool = false;
		bool TeigSorteBool = true;
		bool ConfigFileBool = false;
		bool BlechAusFuellungBool = true;
	};
	Param my_Param;

	enum Errors
	{
		Zutaten,
		Verzierung,
		Teig,
		Form,
		TeigGroesse,
		TeigSorte,
		ConfigFile,
		BlechAusFuellung,
		MaxEnumErrorSIZE
	};

	struct ParamA
	{
		bool ZusammenfassungBool;
	};
	ParamA my_Param2;*/

public:
// Aktuell 01000111
	struct Param
	{
		//1.
		bool ZutatenBool = false; // +
		///////////// 2.
		bool TeigBool = false; // + 
		////////////3.
		bool FormBool = false; //String +
		////// 
		//bool TeigGroesseBool = false; //String + - 
		/////
		bool ConfigFileBool = false; // +
		/////
		//bool BlechAusFuellungBool = false;  // BlechMenge // Rest -
		////
		bool BackzeitBool = false; // -
		//bool Backzeit = true // + 40 Min Kneten usw.
		//Temperatur //
		bool TemperaturBool = false;// +
	};
	Param my_Param;

	enum Errors
	{
		Zutaten,
		Teig,
		Form,
		//TeigGroesse,
		ConfigFile,
		//BlechAusFuellung,
		BackzeitEnum,
		TemperaturBoolEnum,
		MaxEnumErrorSIZE
	};

	struct ParamA
	{
		bool ZusammenfassungBool;
	};
	ParamA my_Param2;


	size_t HashretSave;
	size_t HashGruenSave;

	void setAutomatSteuerungPointer(AutomatSteuerung *  ASPM);

	bool ZutatenPruefen();
	bool TeigPruefen();
	bool FormPruefen();
	bool ConfigPruefen();
	//bool Teigroesse();
	//bool BlechAusfuelungPruefen();

	bool BackzeitPruefen();
	bool TemperaturPruefen();

	bool ZusammenfassungFunc();
	int GetErrorListe();

	int SetSetZutatenTrueFalse(bool);
	int SetTeigTrueFalse(bool);
	int SetFormTrueFalse(bool);
	int SetConfigTrueFalse(bool);
	//int SetTeigroesseTrueFalse(bool);
	//int SetBlechAusfuelungTrueFalse(bool);

	int SetBackzeitTrueFalse(bool);
	int SetTemperaturTrueFalse(bool);

	int SetZusammenfassungFuncTrueFalse(bool);

	//Param * getsParam1();
	//ParamA * getsParam2();


	int TryCatchLoop(string MessageS, string CoutMessages, int ErrorNumber, bool FlagTest, vector<bool>& VectroBool);
	int TryCatchLoop(string MessageS, string CoutMessages, int ErrorNumber, bool FlagTest, vector<bool>& VectroBool, vector<bool>::iterator ITERator);

	ParameterListe();
	~ParameterListe();
};

