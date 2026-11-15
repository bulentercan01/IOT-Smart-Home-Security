#include <Servo.h> //servo motor kütüphanesi tanımlanmıştır.
Servo myservo; //servo motor degiskeni
int hareketsensoru=6; ///SENSÖRÜN BAĞLI OLDUĞU PİN
int led=7;    ///LEDİN BAĞLI OLDUĞU PİN
int sonuc;    ///PIR sonuc degiskeni
int trigPin = 11;    //trig pin baglantı noktası
int echoPin = 12;    //echo pin baglantı noktası
long veri, cm;   // degiskenler
  //hc-sr04 sonuc degiskeni               
int pos = 0;   //servo motor pos degisken değeri

void setup(){
   myservo.attach(9); // servo motorun veri okunacağı pin belirtilmiştir
   pinMode(hareketsensoru, INPUT);  ///VERİ TÜRÜ
   pinMode(trigPin, OUTPUT);  // veri türü
   pinMode(echoPin, INPUT);   // veri türü
}
void loop(){
  sonuc=digitalRead(hareketsensoru); //HAREKET SENSÖR PİNİNDEN VERİ OKUNUR.
  delay(100); //100ms de bir değer oku
  digitalWrite(trigPin, LOW); //sonic ses kapalı
  delayMicroseconds(5); //5ms boyunca
  digitalWrite(trigPin, HIGH);//sonik ses açık 
  delayMicroseconds(10); //10ms boyunca
  digitalWrite(trigPin, LOW); //sonic ses kapalı
  
  veri = pulseIn(echoPin, HIGH); //echoPin girişinden veri oku
  cm = (veri/2) / 29.1; //echopinden okunan veriyi cm ye donustur
  delay(50);
  
  if(sonuc==HIGH && cm<=150)   //eğer hareket sensörü hareket algılar ve
                               // mesafe sensörüde 150 cm de yakında engel algılarsa
    myservo.write(180);        // servo motor 180 derece doner ve kapı kilitlenir.
  
  
}

