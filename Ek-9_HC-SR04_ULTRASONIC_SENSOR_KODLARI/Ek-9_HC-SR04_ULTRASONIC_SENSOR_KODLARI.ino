int trigPin = 11;    //trig pin baglantı noktası
int echoPin = 12;    //echo pin baglantı noktası
long veri, cm;   // degiskenler
void setup() {
  Serial.begin (9600);  ///seri port başlatılır.
  pinMode(trigPin, OUTPUT);  // veri türü
  pinMode(echoPin, INPUT);   // veri türü
}
void loop()
{
  digitalWrite(trigPin, LOW); //sonic ses kapalı
  delayMicroseconds(5); //5ms boyunca
  digitalWrite(trigPin, HIGH);//sonik ses açık 
  delayMicroseconds(10); //10ms boyunca
  digitalWrite(trigPin, LOW); //sonic ses kapalı
  veri = pulseIn(echoPin, HIGH); //echoPin girişinden veri oku
  cm = (veri/2) / 29.1; //okunan veriyi cm ye donustur
  Serial.print(cm); //ekrana uzaklığı yaz
  Serial.print("cm"); //ekrana cm yaz
  Serial.println(); 
  delay(250); //250 ms de yenile   
  }

