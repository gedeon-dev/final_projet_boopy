#include "Fichier.h"

Fichier::Fichier()
{
	//manipulation de la date et de l'heure
	time_t timestampActuel; // recupere  timestampactuel
	time(&timestampActuel); // initialise la methode time avec le timestampActuel
	tm* dateHeure = localtime(&timestampActuel); //strut tm de la librairie ctime
	heure = "" + to_string(dateHeure->tm_hour) + "h:" + to_string(dateHeure->tm_min) + "mn";
	date = "" + to_string(dateHeure->tm_mday) + "-" + to_string(1 + dateHeure->tm_mon) + "-" + to_string(1900 + dateHeure->tm_year);
}

void Fichier::enregistre_Fichier(string latitude = 0, string longitude = 0, double profondeur = 0)
{
	//traitement du fichier
	ofstream file("donnee_batymetrique.csv", ios::app); // on ouvre le flux en mode ajout
	//file.seekp(0, ios::end); // on se place en fin de fichier
	int taille = file.tellp(); // on recupere la taille


	if (taille != 0) {
		file << date << "  ,  " << heure << "  ,  " << profondeur << "  ,  " << latitude << "  ,  " << longitude << endl;
		//cout << date << "," << heure << "  ,  " << profondeur << "  ,  " << latitude << "  ,  " << longitude << endl;
	}
	else {
		file << "date" << "," << "heure" << "," << "profondeur" << "," << "latitude" << "," << "longitude" << endl;
		file << date << "  ,  " << heure << "  ,  " << profondeur << "  ,  " << latitude << "  ,  " << longitude << endl;
		//cout << date << "," << heure << "  ,  " << profondeur << "  ,  " << latitude << "  ,  " << longitude << endl;
	}

}

Fichier::~Fichier()
{
}
