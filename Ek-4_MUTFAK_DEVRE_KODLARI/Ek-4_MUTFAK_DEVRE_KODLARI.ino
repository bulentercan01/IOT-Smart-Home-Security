const int lm35=A0;    //LM35 İN BAĞLANDIĞI PİN
float voltaj_deger=0; //DEĞİŞKEN
float sicaklik=0;     //DEĞİŞKEN
float gelen_veri=0;   //DEĞİŞKEN
int role1=6;        //ROLENİN BAĞLI OLDUĞU PİN
int sensorValue;   //DEĞİŞKEN

#include<LiquidCrystal.h>;      /// LCD KÜTÜPHANESİ
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);  /// LCD PN BAĞLANTI NOKTALARI
void setup() {
  lcd.begin(16,2); /// LCD EKRAN BOYUTU
  pinMode(role1,OUTPUT);   ///ROLEPİN TANITIMI
  }

void loop() {
  gelen_veri=analogRead(lm35);        ///LM35 İN OKUDUĞU DEĞER 
  voltaj_deger=(gelen_veri/1023.0)*5000;    ///DEĞER DONUŞUMU
  sicaklik=(voltaj_deger/10)-15;          ///DEĞER DONUŞUMU
  lcd.clear(); ///LCD EKRAN TEMİZLEME KODU
  lcd.home(); /// LCD NİN  0,0 KOORDINATINA GELİR
  lcd.print("ISI: ");   //EKRANA YAZI YAZDIRILIR.
  lcd.print(sicaklik);    //EKRANA DEGER YAZDIRILIR.
  delay(200);             //200 MS DE BİR YENİLENİR
   sensorValue = analogRead(A2);  ///A2 NOKTASINDAN DEĞER OKUNUR.
  lcd.setCursor(0,1);           ///LCD YAZININ YAZILACAĞI KOORDİNAT
  lcd.print("GAZ DEGER: ");      //EKRANA YAZI YAZDIRILIR.
  lcd.print(sensorValue);       //EKRANA DEGER YAZDIRILIR.
  delay(2000);                  //200 MS DE BİR YENİLENİR
  
  if(sicaklik>=30||sensorValue>=110){     //EĞER SICAKLIK 30 DEĞERİNİN ÜZERİNA YADA            GAZ DEĞERİ 110 UN UZERİNE ÇIKARSA
    digitalWrite(role1,LOW);                  // ROLE KAPANIR FAN
  }
  else{                                     //ŞART SAĞLANMAZ İSE ROLE AÇIK KALIR.
    digitalWrite(role1,HIGH);
  }
}

