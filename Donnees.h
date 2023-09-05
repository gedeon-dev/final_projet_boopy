#pragma once
#include "Gps.h"
#include "Sonar.h"
struct data
{
	double profondeur;
	string latitude;
	string longitude;
};
class Donnees
{
private:
	Sonar sonar;
	Gps gps;
	data batymetriqueData;
	gpsData coordonneeGps;
public:
	Donnees();
	~Donnees();
	void acquisition_Data();
	data get_Data();
};
