#pragma once
#include <thread>
#include "AutomatSteuerung.h"


class AusnahmenUndThreadsMon : public AutomatSteuerung
{
	bool AusnahmenMonitorStatus = true;
	AutomatSteuerung * AutomatSteuerungAusnahmenUndThreadsMo;
public:
	void setAutomatSteuerungPointer(AutomatSteuerung *  ASATM);
	bool SetAusnahmenMonitorTrueFalse(bool);
	bool StartAusnahmenMonitor();
	std::thread StartThreadAusnahmeMonitor();


	AusnahmenUndThreadsMon();
	~AusnahmenUndThreadsMon();
};