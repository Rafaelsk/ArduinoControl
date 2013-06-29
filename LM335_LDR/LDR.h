//22 de junio de 2013
//Universidad de Oriente
//Postgrado en Ingeniería Eléctrica
//Especialización en Automatización e Informática Industrial
//Cohorte XIII
//Microprocesadores aplicados a Control
//Prof. Alfonso Alfonsi
//
//Luis   Mata      16.171.889
//Marlon Trujillo  18.278.778
//Rafael Solorzano 16.478.353

#ifndef LDR_h
#define LDR_h

#include "Arduino.h"

#define pinLDR A0
const float R = 6200.0; //Resistencia del divisor debe ser igual o menor al valor mínimo de la LDR

void setupLDR();
float readLDR(byte units, boolean serialDebug);

#endif
