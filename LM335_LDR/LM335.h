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

#ifndef LM335_h
#define LM335_h

#include "Arduino.h"

#define pinLM335 A1

void setupLM335();
float readLM335(byte units, boolean serialDebug);

#endif
