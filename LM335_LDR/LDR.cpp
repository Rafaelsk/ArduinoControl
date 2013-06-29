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

#include "LDR.h"

void setupLDR()
{
  pinMode(pinLDR, INPUT);
  digitalWrite(pinLDR, LOW); //disable internal pul-up resistor
}

float readLDR(byte units, boolean serialDebug)
{
  int analogLDR;
  float voltageLDR, LDR, Luz;

  analogLDR = analogRead(pinLDR);

  if(!units)
  {
    if(serialDebug)
    {
      Serial.print("Conversion ADC LDR: ");
      Serial.println(analogLDR);
    }

    return ((float) analogLDR);
  }

  voltageLDR = (float)analogLDR*5.0/1023.0;

  if(units == 'V')
  {
    if(serialDebug)
    {
      Serial.print("Voltaje LDR: ");
      Serial.print(voltageLDR);
      Serial.println(" V");
    }

    return (voltageLDR);
  }

  LDR = R*(float)analogLDR/(float)(1023-analogLDR);

  if(units == 'R')
  {
    if(serialDebug)
    {
      Serial.print("Resistencia LDR: ");
      Serial.print(LDR);
      Serial.println(" Ohms");
    }

    return (LDR);
  }

  Luz = 100.0*(R/LDR); //Calculo experimental para obtener un valor entre 0 y 100%

  if(units == 'L')
  {
    if(serialDebug)
    {
      Serial.print("Luz LDR: ");
      Serial.print(Luz);
      Serial.println(" %");
    }

    return (Luz);
  }

  if(serialDebug)
  {
    Serial.print("Error LDR: Wrong units parameter");
  }  
  return 0.0; //Wrong units parameter
}
