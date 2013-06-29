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

void setupLM335()
{
  pinMode(pinLM335, INPUT);
  digitalWrite(pinLM335, LOW); //disable internal pul-up resistor 
}

float readLM335(byte units, boolean serialDebug)
{
  int analogTemp;
  float voltageTemp, TempK, TempC, TempF;

  analogTemp = analogRead(pinLM335);

  if(!units)
  {
    if(serialDebug)
    {
      Serial.print("Conversion ADC LM335: ");
      Serial.println(analogTemp);
    }

    return ((float) analogTemp);
  }

  voltageTemp = (float)analogTemp*5.0/1023.0;

  if(units == 'V')
  {
    if(serialDebug)
    {
      Serial.print("Voltaje LM335: ");
      Serial.print(voltageTemp);
      Serial.println(" V");
    }

    return (voltageTemp);
  }

  TempK = voltageTemp*100.0; // 10mV/K

  if(units == 'K')
  {
    if(serialDebug)
    {
      Serial.print("Temp LM335: ");
      Serial.print(TempK);
      Serial.println(" K");
    }

    return (TempK);
  }

  TempC = TempK - 273.0;

  if(units == 'C')
  {
    if(serialDebug)
    {
      Serial.print("Temp LM335: ");
      Serial.print(TempC);
      Serial.println(" C");
    }

    return (TempC);
  }

  TempF = TempC*(9.0/5.0)+32.0;

  if(units == 'F')
  {
    if(serialDebug)
    {
      Serial.print("Temp LM335: ");
      Serial.print(TempF);
      Serial.println(" F");
    }

    return (TempF);
  }

  if(serialDebug)
  {
    Serial.print("Error LM335: Wrong units parameter");
  }  
  return 0.0; //Wrong units parameter
}
