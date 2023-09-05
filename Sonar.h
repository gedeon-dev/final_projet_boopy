#pragma once
#include <iostream>
#include <wiringPi.h>
using namespace std;
class Sonar
{
private:

	int Trigger; // Broche Trigger
	int Echo; // Broche Echo
	double distance; // Distance
	volatile long Debut; // Variable Debut Chrono
	volatile long Fin; // Variable Fin Chrono
	long Temps; // Variable Temps d'�mission

public:
	void Init(int trigger, int echo); // Initialise le Capteur
	double Distance(); // Calcule le temps d'�mission
	double Calcule(); // Calcule la distance en fonction du temps d'�mission

	Sonar(int trigger = 23, int echo = 24); // Constructeur
	~Sonar(); // Destructeur
};

