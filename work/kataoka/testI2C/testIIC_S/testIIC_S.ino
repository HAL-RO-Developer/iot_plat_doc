/* 
 *  スレーブ側プログラム
 *
 *  Arduino pro mini SDA-A4 SCL-A5
 *  呼ばれるたびに、インクリメント
 */


#include <Wire.h>

byte b=0;

void setup() {
  Wire.begin(8);// スレーブ ID #8
  Wire.onRequest(requestEvent);
}

void loop() {
}

void requestEvent() {
  Wire.write(b++);
}
