#include "Donnees.h"

Donnees::Donnees()
{
	sonar = Sonar();
	gps = Gps();
}

Donnees::~Donnees()
{
}

void Donnees::acquisition_Data()
{
	coordonneeGps = gps.acquition_Gps();
	batymetriqueData.profondeur = sonar.Distance();
	cout << batymetriqueData.profondeur << endl;
}

data Donnees::get_Data()
{
	acquisition_Data();
	batymetriqueData.latitude = coordonneeGps.latitude;
	batymetriqueData.longitude = coordonneeGps.longitude;
	return batymetriqueData;
}
