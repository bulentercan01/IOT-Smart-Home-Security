float sicaklik; //Analog değeri dönüştüreceğimiz sıcaklık 
float olculendeger; //Ölçeceğimiz analog değer
int sicaklikpin=0;  //Analog değer girişi
int role1=6;
void setup () {
  Serial.begin(9600); //Seri haberleşme,sıcaklığı ekrandan takip edeceğiz.
  pinMode(role1,OUTPUT);
}
void loop () {
 olculendeger = analogRead(sicaklikpin); //A1'den değeri alacak
 olculendeger = (olculendeger/1023)*5000;//değeri mV'a dönüştürecek 
 sicaklik = olculendeger /10,0; // mV'u sicakliğa dönüştürecek
 Serial.print("Sicaklik : ");
 Serial.print (sicaklik);
 Serial.println (" derece");
 delay (1000); //1sn aralıklarla yapacak
}

