#include "Arduino.h"
#include "Luciole.h"


Luciole::Luciole(int p){
	pinMode(p,OUTPUT);
	pin = p;
	horloge = random(1, cycle_length);
	threshold = flash_length;
}
void Luciole::setDelay(){
	reset_level = threshold;
	window = window - 1;
}
void Luciole::setAdvance(){
	reset_level = 0;
	window = threshold + 1;
}
void Luciole::increment_clock(){
	horloge = horloge + 1;
	if(horloge == cycle_length){
		horloge = 0;
	}
}
void Luciole::look(){		//point à éclaircir car adaptation pas fidèle au modèle netlogo.
	val_capt = analogRead(pinCapt);
	if(val_capt <= lum_amb - 35){
		horloge = reset_level;
	}
}
void Luciole::recolor(){
	if(horloge < threshold){
		digitalWrite(pin,HIGH);
	}else{
		digitalWrite(pin,LOW);
	}
}
int Luciole::getHorloge(){
	return horloge;
}
int Luciole::getThreshold(){
	return threshold;
}
int Luciole::getWindow(){
	return window;
}