#include <wiringPi.h>
#include "Donnees.h"
#include "Fichier.h"
#include <thread>
#include <chrono>

static bool finThread = false;

void tache_Acquisition(Donnees donneeBatymetrique, Fichier enregistrement, data &liste) {
	while (!finThread) {
		donneeBatymetrique.acquisition_Data();
		liste = donneeBatymetrique.get_Data();
		enregistrement.enregistre_Fichier(liste.latitude, liste.longitude, liste.profondeur);
		std::this_thread::sleep_for(chrono::seconds(3));
	}
}
/*void tache_position_Lora(Clora envoie, data liste) {
	while (!finThread) {
		envoie.send(liste.longitude, liste.latitude);
		std::this_thread::sleep_for(chrono::seconds(10));
	}
}*/
void tache_position_Lora() {
	while (!finThread) {
		cout << "hello" << endl;
	}
}
int main(void)
{
	//acquisition des donnees

	data donnee;
	Donnees batymetrie = Donnees();
	Fichier enregistre = Fichier();
	//Clora sendLora = Clora();


	//debut thread
	thread acquisition_donnees_batymetriques(tache_Acquisition, batymetrie, enregistre, donnee);
	thread envoie_position_lora(tache_position_Lora, batymetrie, donnee);
	thread envoie_position_lora(tache_position_Lora);
	cin.get();
	finThread = true;
	//acquisition_donnees_batymetriques.join(); //on s'assure que le thread prenne fin avant que le programme se termine
	//envoie_position_lora.join(); //on s'assure que le thread prenne fin avant que le programme se termine
	//fin thread

	//system("python3 PythonApplication.py");

	
	donnee = batymetrie.get_Data();
	cout << donnee.latitude << endl;
	cout << donnee.longitude << endl;
	cout << donnee.profondeur << endl;

	//enregistrement des donnees
	enregistre.enregistre_Fichier(donnee.latitude, donnee.longitude, donnee.profondeur);
}