#include<Servo.h>

Servo servo1;

void setup() {
  Serial.begin(115200);
    servo1.attach(5); //ESP8266ボードのD1をサーボ用に設定
    
}

void loop() {
  unsigned long t1;
  unsigned long t2;
  //0→45→90→135→180の順で回す
   servo1.write(0);
    delay(1000);
    t1 = micros();//測定開始
    servo1.write(45);
    t2 = micros();//測定終了
    Serial.println(t2-t1);//表示
    delay(1000);
    servo1.write(90);
    delay(1000);
    servo1.write(135);
    delay(1000);
    servo1.write(180);
    delay(1000);
}

