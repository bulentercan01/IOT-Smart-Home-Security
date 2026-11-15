#include <Servo.h> //servo motor kütüphanesi tanımlanmıştır.
Servo myservo;  //değişken atanmıştır                
int pos = 0;   
void setup()
{
  myservo.attach(9); // servo motorun veri okunacağı pin belirtilmiştir  
}
void loop()
{
 for(pos = 0; pos < 180; pos += 1)    /// bu for döngüsü ile motor 0 dereceden 180 dereceye doğru
  {                                  /// 1 er derece artarak hareket etmiştir.
    myservo.write(pos);              
    delay(15);                       /// 15ms hareket süresi
  }
  for(pos = 180; pos>=1; pos-=1)    /// bu for döngüsü ile motor 180 dereceden 0 dereceye doğru 
  {                                 ///1 er derece azalarak hareket etmiştir.
    myservo.write(pos);              
    delay(15);                      /// 15ms hareket süresi
  } 
}

