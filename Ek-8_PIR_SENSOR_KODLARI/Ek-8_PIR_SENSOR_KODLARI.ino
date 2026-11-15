int hareketsensoru=6; ///SENSÖRÜN BAĞLI OLDUĞU PİN
int led=7;    ///LEDİN BAĞLI OLDUĞU PİN
int sonuc;    ///DEĞİŞKEN

void setup(){
  pinMode(hareketsensoru, INPUT);  ///VERİ TÜRÜ
  Serial.begin(9600);  //SERİ PORT EKRANI BAŞLATILIR.
}

void loop(){
  sonuc=digitalRead(hareketsensoru); //SENSÖR PİNİNDEN VERİ OKUNUR.
  Serial.write(sonuc);
  if(sonuc==HIGH){  ///HAREKET VARSA LED Dİ YAK
    digitalWrite(led,HIGH);
  }else{           // HAREKET YOKSA LEDİ SONDUR
    digitalWrite(led,LOW);
  }
}

