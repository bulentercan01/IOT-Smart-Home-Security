int kirmiziPin = 2; ///PİN BAGLANTISI
int yesilPin = 3;  ///PİN BAGLANTISI
int maviPin = 4;   ///PİN BAGLANTISI
int i, j, k;    
void setup() {
  pinMode(kirmiziPin,OUTPUT);  //PİNDEN GELEN VERİNİN TÜRÜ
  pinMode(yesilPin,OUTPUT);    //PİNDEN GELEN VERİNİN TÜRÜ
  pinMode(maviPin,OUTPUT);     //PİNDEN GELEN VERİNİN TÜRÜ
}
void renkAyarla(int kirmizi, int yesil, int mavi)
{
 kirmizi = 255 - kirmizi;   //RENK KOD FORMULU
 yesil = 255 - yesil;      //RENK KOD FORMULU
 mavi = 255 - mavi;       //RENK KOD FORMULU
 analogWrite(kirmiziPin, kirmizi);   //LEDİN KIRMIZI IŞIĞI YAKILIR
 analogWrite(yesilPin, yesil);       //LEDİN YEŞİL IŞIĞI YAKILIR
 analogWrite(maviPin, mavi);         //LEDİN MAVİ IŞIĞI YAKILIR
}
void loop() {              // FOR DONGÜSÜYLE OLUŞTURULABİLECEK TÜM RENKLER OLUŞURULUR.
/* for(i=0;i<=255;i++){
  for(j=0;j<=255;j++){
    for(k=0;k<=255;k++){
      renkAyarla(i+25, j+25, k+25);
      delay(1); // 1MS DE DEĞİŞİR
    }}}*/

 renkAyarla(255,0,0);
}

