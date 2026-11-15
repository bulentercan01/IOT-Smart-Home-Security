int kirmiziPin = 9;
int yesilPin = 10;
int maviPin = 11;
int role1=6;
void setup() {
  pinMode(kirmiziPin,OUTPUT);
  pinMode(yesilPin,OUTPUT);
  pinMode(maviPin,OUTPUT);
  pinMode(role1,OUTPUT);
  Serial.begin(9600); //Seri iletişimi başlatır
}
void renkAyarla(int kirmizi, int yesil, int mavi)
{
 kirmizi = 255 - kirmizi;
 yesil = 255 - yesil;
 mavi = 255 - mavi;
 analogWrite(kirmiziPin, kirmizi);
 analogWrite(yesilPin, yesil);
 analogWrite(maviPin, mavi);
}
void loop()
{
if(Serial.available()) // Eğer Bluetooth bağlantısı varsa kodaları çalıştırır
{
char data = Serial.read();
delay(100);
if(data=='a'){
 renkAyarla(126, 126, 163); // ledi yesil olarak yak

}
if(data=='A'){
  digitalWrite(kirmiziPin,LOW);
  digitalWrite(yesilPin,LOW);
  digitalWrite(maviPin,LOW);
}if(data=='b'){
  renkAyarla(244, 45, 55);// ledi mavi olarak yak
}
if(data=='B'){// ledi kapat
  digitalWrite(kirmiziPin,LOW);
  digitalWrite(yesilPin,LOW);
  digitalWrite(maviPin,LOW);
}
if(data=='c'){ // röleyi aktif et / role calısınc fanda calısır
  digitalWrite(role1,LOW);
}
else if(data=='C'){ //roleyi deaktif et //
  digitalWrite(role1,HIGH);

}else{
  digitalWrite(role1,HIGH);// roleyi deaktif et
}

if (data=='d'){
  renkAyarla(45, 45, 188); //ledi sarı yak
}
if(data=='D'){// ledi kapat
  digitalWrite(kirmiziPin,LOW);
  digitalWrite(yesilPin,LOW);
  digitalWrite(maviPin,LOW);
}
}
}

