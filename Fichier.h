#pragma once
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
class Fichier
{
private:
	string heure = "";
	string date = "";
public:
	Fichier();
	void enregistre_Fichier(string longitude, string latitude, double profondeur);
	~Fichier();
};

