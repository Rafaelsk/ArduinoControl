#define LDR   A0
#define LM335 A1

void setup()
{
 Serial.begin(9600);
 pinMode(LDR, INPUT);
 pinMode(LM335, INPUT);
 digitalWrite(LDR, LOW); //disable internal pul-up resistor
 digitalWrite(LM335, LOW); //disable internal pul-up resistor 
}

void loop()
{
  int vTemp, vLuz;
  float temp, ldr, luz;
  vTemp = analogRead(LM335);
  vLuz = analogRead(LDR);
  
  Serial.print("Voltaje LM335: ");
  Serial.print(vTemp);
  
  Serial.print(" Voltaje LDR: ");
  Serial.println(vLuz);
  
  temp = (float)vTemp*(500.0/1023.0) - 273.0;
  
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  
  ldr = 6200.0*(float)vLuz/(float)(1023-vLuz);
  
  Serial.print("LDR: ");
  Serial.print(ldr);
  Serial.println(" Ohms");

  luz = 620000/ldr;
  
  Serial.print("Luz: ");
  Serial.print(luz);
  Serial.println(" %");

  delay(2000);
  
}
