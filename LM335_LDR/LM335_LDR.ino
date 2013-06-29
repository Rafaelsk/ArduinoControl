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

#include "LM335.h"
#include "LDR.h"

void setup()
{
  Serial.begin(9600);
  setupLM335();
  setupLDR();
}

void loop()
{
  Serial.println("     *****   LM335   *****     ");
  readLM335(0, true);  //Lee conversion del ADC del valor del LM335 y envia por serial
  readLM335('V', true);//Lee voltaje del LM335 y envia por serial
  readLM335('K', true);//Lee temperatura en Kelvin y envia por serial
  readLM335('C', true);//Lee temperatura en Celsius y envia por serial
  readLM335('F', true);//Lee temperatura en Farenheit y envia por serial
  Serial.println("");

  Serial.println("     *****   LDR   *****     ");
  readLDR(0, true);  //Lee conversion del ADC del voltaje sobre el LDR y envia por serial
  readLDR('V', true);//Lee el voltaje sobre el LDR y envia por serial
  readLDR('R', true);//Lee el valor del LDR y envia por serial
  readLDR('L', true);//Lee el porcentaje de luz sobre el LDR y envia por serial
  Serial.println("");

  delay(2000);

}
