#ifndef Luciole_h
#define Luciole_h

#include "Arduino.h" 

//using namespace std;
class Luciole{
		
	static const int flashes_to_reset = 1;	//nombre de lucioles présentes pour se synchroniser
	static const int flash_length = 1;		//longueur du flash
	static const int cycle_length = 10;		//longueur d'un cycle
	static const int pinCapt = A0;			//entrée analogique pour le capteur de température
	static const int lum_amb = 450;			//Valeur de la lumière ambiante pour point de comparaison

	
	

	public:									// constructeurs et méthodes publiques
		Luciole(int p);
		void look();
		void increment_clock();
		void setDelay();
		void setAdvance();
		void recolor();
		int getHorloge();
		int getWindow();
		int getThreshold();


	protected:								//attributs protected pour réutilisation du code
		int horloge;		//horloge propre de chaque luciole
		int pin;			//sortie digitale de la LED
		int threshold;		//repère à partir duquel une luciole stoppe son flash 
		int reset_level;	//Endroit de l'horloge à partir de laquelle la luciole se rest lorsqu'elle voit un autre flash
		int window;			//fenêtre de temps.
		int val_capt;
		

};
#endif