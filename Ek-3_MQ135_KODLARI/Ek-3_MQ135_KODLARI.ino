const int analogInPin = A0;  
const int ledPin = 13;              

int veri = 0;        
void setup() { 
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT); 
}
void loop() {
  veri = analogRead(analogInPin);        
    if (veri >= 150)
  {    digitalWrite(ledPin, HIGH);}
  else
  {  digitalWrite(ledPin, LOW);}

  Serial.print("Okunan Değer = " );                       
  Serial.println(veri);   
  delay(750);                     
}
