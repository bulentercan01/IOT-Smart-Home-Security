#include<LiquidCrystal.h>// LCD KÜTÜPHANESİ BELİRTİLİYOR
LiquidCrystal lcd(2, 3, 4, 5, 12, 13); // LCD NİN BAĞLI OLDUĞU PİNLER
void setup() {
lcd.begin(16,2); //LCD EKRANIN 16X2 ALANA SAHİP OLDUĞU BİLDİRİLİYOR

}
void loop() {
lcd.clear();    /// LCD EKRAN TEMİZLENİYOR
lcd.setCursor(0,0); //YAZININ BAŞLAYACAĞI KORDİNAT VERİLİYOR.
lcd.print("16x2 LCD EKRAN"); // EKRANA YAZI YAZDIRILIYOR.
}

