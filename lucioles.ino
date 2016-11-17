#include "Luciole.h"


int h;
int t;
int w;
Luciole *tab_lucioles[7]; //tableau contenant nos objets Luciole
int a;

void setLucioles(){		//on initialise les lucioles
	a = analogRead(A0);
	for(int i = 0; i < 7; i++){
		tab_lucioles[i] = new Luciole(i+7);
		tab_lucioles[i]->setDelay();
		tab_lucioles[i]->recolor();
	}
	
}

void setup() {      
	Serial.begin(9600);
	setLucioles();
}


void loop() {
	for(int i = 0;i < 7; i++){
		tab_lucioles[i]->increment_clock();			//Boucle qui traitent : LES PERCEPTIONS
		h = tab_lucioles[i]->getHorloge();
		t = tab_lucioles[i]->getThreshold();
		w = tab_lucioles[i]->getWindow();
		if((h > w) && (h >= t)){					//on effectue LES DÉCISIONS
			tab_lucioles[i]->look();
		}
	}
	for(int i = 0;i < 7; i++){						//Boucle qui effectue les ACTIONS
		tab_lucioles[i]->recolor();
	}
	delay(100);
}
