/*
 * モジュール応答時間計測プログラム
 */

#define SW_PIN 14

unsigned long time1;
unsigned long time2;
unsigned long result;

void setup() {
  Serial.begin(115200);

  pinMode(SW_PIN,INPUT);
}

void loop() {

  
  if(digitalRead(SW_PIN) == HIGH){
    time1 = micros();
    while(digitalRead(SW_PIN) == HIGH){}
  }else{
    time2 = micros();
    result = time2 - time1;
    Serial.println(result);
  }
  
}
