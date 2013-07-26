#include <PID_v1.h> //Version 1.1.0 de otro usuario
/*
PID()
Compute()
SetMode()
SetOutputLimits()
SetTunings()
SetSampleTime()
SetControllerDirection()
*/
#include <MsTimer2.h>

#define IN1 5
#define ENA 10
#define IN2 11
#define CSA A0

#define DEADBAND 55

#define LED 13

#define encA 2
#define encB 3
#define ledA 6
#define ledB 7

double encoderPos = 0.0;
double lastAEncoder = 0.0;
double desiredPosition = 0.0;

//Define Variables we'll be connecting to
double Output;

//Specify the links and initial tuning parameters
//1.7308,133.61,0.08654
PID myPID(&encoderPos, &Output, &desiredPosition,0.5,0.0,0.0, DIRECT);

void setup()
{
  Serial.begin(9600);
  
  digitalWrite(ENA, LOW);
  
  pinMode(IN1, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  pinMode(CSA, INPUT);
  
  pinMode(encA, INPUT);
  pinMode(encB, INPUT);
  digitalWrite(encA, HIGH);
  digitalWrite(encB, HIGH);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);

  pinMode(LED, OUTPUT);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
  digitalWrite(ENA, HIGH);
  attachInterrupt(0,interrEncoder,CHANGE);
  
  //MsTimer2::set(20,interrupcionTs);
  
  //initialize the variables we're linked to
  desiredPosition = 500.0;

  myPID.SetOutputLimits(-255.0, 255.0);
  myPID.SetSampleTime(20);
  //turn the PID on
  myPID.SetMode(AUTOMATIC);
  
  //MsTimer2::start();
}

void loop()
{
  
  if(Serial.available())
    desiredPosition = 56*(Serial.read()-'0');
    
  if(millis()%1000 == 0)
  {
    Serial.print("PID: ");
    Serial.println(Output);
    Serial.print("SP: ");
    Serial.println(desiredPosition);
    Serial.print("Y: ");
    Serial.println(encoderPos);
  }
  
  myPID.Compute();
  setMotor(Output);
}

void interrEncoder()
{
  int A = digitalRead(encA);
  int B = digitalRead(encB);
  
  digitalWrite(ledA, A);
  digitalWrite(ledB, B);
  
   if( (lastAEncoder == LOW) && (A == HIGH) )
   {
     if(B == LOW)
     {
       encoderPos--;
     }
     else
     {
       encoderPos++;
     }
   } 
   lastAEncoder = A;
}

void forward(int value)  //value is pwm value from 0 to 255
{
  analogWrite(IN1,value);
  digitalWrite(IN2,LOW);
}

void backward(int value) //value is pwm value from 0 to 255
{
  analogWrite(IN2,value);
  digitalWrite(IN1,LOW);
}

void setMotor(double output)
{ 
  if(output > 1)
  {
    forward(output>DEADBAND? output:DEADBAND);
  } 
  else if(output < -1)
  {
    backward(output<-DEADBAND? -output:DEADBAND);
  }
  else
  {
    forward(0);
  }
}

void interrupcionTs()
{
  myPID.Compute();
  setMotor(Output);
}
