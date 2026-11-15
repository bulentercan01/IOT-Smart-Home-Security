# 🏡 IoT Tabanlı Akıllı ve Güvenli Ev Otomasyonu (Dual-Verification Security)

![IoT & Embedded](https://img.shields.io/badge/IoT_%26_Embedded-333333?style=for-the-badge&logo=internet-of-things&logoColor=white)
![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Bluetooth](https://img.shields.io/badge/Bluetooth-0082FC?style=for-the-badge&logo=bluetooth&logoColor=white)

Bu proje, TEİAŞ bünyesinde gerçekleştirilen Ar-Ge stajı kapsamında geliştirilmiş, ev içi tehlikeleri (yangın/gaz kaçağı) otonom olarak önleyen ve asılsız alarmları filtreleyen **çift faktörlü (dual-verification)** bir kapalı devre akıllı ev ve güvenlik sistemidir.

## 📌 Proje Amacı ve Operasyonel Vizyon
Günümüz akıllı ev sistemlerinin yüksek maliyetli ve dış müdahalelere (Wi-Fi/Cloud) açık olmasından yola çıkılarak, tamamen bağımsız (Off-Grid) ve düşük maliyetli bir güvenlik prototipi tasarlanmıştır. Sistem üç temel mimariye dayanır:
1.  **Otonom Çevresel Güvenlik (Kök Neden Önleme):** Mutfak gibi riskli alanlarda sıcaklık (LM35) ve gaz (MQ-135) eşik değerleri aşıldığında, sistem harici komut beklemeden otonom olarak röleleri tetikler ve havalandırma fanlarını devreye sokarak tehlikeyi kökünden çözer.
2.  **Çift Faktörlü Hırsızlık Önleme (Filtreleme):** Klasik sistemlerin en büyük sorunu olan evcil hayvanların (kedi/köpek) asılsız alarm üretmesini engellemek için, hareket (PIR) sensörü ile mesafe (Ultrasonik) sensörü aynı algoritmada işlenmiştir. Sadece hareket algılandığında VE obje 150 cm'den yakın (insan boyutu) olduğunda servo motor kapıyı mekanik olarak kilitler.
3.  **Kablosuz Kapalı Devre Kontrol:** HC-06 Bluetooth modülü sayesinde, internet bağlantısına ihtiyaç duymadan Android işletim sistemli cihazlardan RGB aydınlatma ve fan sistemleri güvenli bir şekilde kontrol edilebilir.

## ⚙️ Sistem Mimarisi ve Algoritma
Tüm karar mekanizmaları Arduino UNO R3 (ATmega328P) üzerinde C++ ile koşmaktadır.
- **Sensör Veri İşleme:** Analog (Isı/Gaz) ve Dijital (Hareket/Uzaklık) pinlerden alınan veriler, mili-saniye (ms) düzeyinde işlenip çapraz doğrulamaya tabi tutulur.
- **Eyleyiciler (Actuators):** 5V Röle kartı, Servo Motor (Kapı kilidi için), RGB LED ve DC Motor (Havalandırma).
- **Güç Yönetimi:** Sistem elemanlarının stabil çalışması için LM2596 voltaj regülatörü ile güvenli akım/voltaj dağıtımı sağlanmıştır.

## 🛠️ Kullanılan Donanım Bileşenleri
- **Kontrolcü:** Arduino UNO R3
- **Çevresel Sensörler:** LM35 (Sıcaklık), MQ-135 (Gaz/Duman)
- **Güvenlik Sensörleri:** HC-SR501 (PIR Hareket), HC-SR04 (Ultrasonik Mesafe)
- **Haberleşme:** HC-06 Bluetooth Modülü
- **Çıktı & Mekanik:** 16x2 LCD Ekran, 4'lü Röle Kartı, MG90S Servo Motor

## 💻 Kurulum ve Test
1.  Repoda bulunan ilgili `.ino` dosyalarını (Güvenlik, Çevresel Kontrol vb.) Arduino IDE ile açın.
2.  Gerekli kütüphanelerin (`LiquidCrystal.h`, `Servo.h`) kurulu olduğundan emin olun.
3.  Sensör ve eyleyici (actuator) bağlantılarını pin tanımlamalarına göre breadboard/PCB üzerine kurun.
4.  Kodu derleyip karta yükledikten sonra, Bluetooth üzerinden komut göndermek için standart bir Bluetooth Terminal veya "Arduino Bluetooth Home" türevi bir Android uygulaması kullanabilirsiniz.
