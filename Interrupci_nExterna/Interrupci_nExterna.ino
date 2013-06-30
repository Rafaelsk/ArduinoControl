
#define ledPin 13
#define digiInPin 3

long lastTime;

void setup() {
  Serial.begin(9600);
  
  pinMode(digiInPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  attachInterrupt(0,interrupcion1,CHANGE);
  
  lastTime = 0;
}

void loop() {
  digitalWrite(ledPin,digitalRead(digiInPin));
}

void interrupcion1() {
  long actual = millis();
  float aux = (actual-lastTime);
  aux /= 1000;
  Serial.println(aux);
  lastTime = actual;
}
