/* 
 *  マスター側プログラム
 *  
 *  ESP8266 SDA-IO4 SCL-IO5
 */  
/*  スレーブアドレスの取得
#include <Wire.h>

void setup() {
  Wire.begin();                       // 引数無しは (4, 5)と同じ (SDA,SCL)
  Serial.begin(115200);
  Serial.println(); Serial.println("Start I2C address scanner"); 
  }
 
void loop() {
  Serial.println("     0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F");
  for (byte n = 0; n <= 0x7F; n++) {  // I2Cアドレスを指定
    adrCheck(n);                      // デバイス有無を調べ結果を出力
  }
  Serial.println();                  // 1行空けて
  delay(2000);                        // 2秒待って繰り返す
}
 
void adrCheck(byte adr) {
  byte    dummy;                      // Dummy
  if ((adr & 0x0F) == 0) {            // 行の先頭なら
    print_hex2chr(adr);               // アドレスを出力
    Serial.print(":");
  }
  Serial.print(" ");                 // 区切り用に空白を入れる
 
  if (adr < 8 || adr > 0x77) {        // 予約アドレスの範囲は
    Serial.print("xx");              // xx 表示
  }
  else {                              // アドレスにデバイスがあるか？
    Wire.beginTransmission(adr);
    Wire.write(&dummy, 0);
    if (Wire.endTransmission() == 0) { // 書き込みが正常終了していたら
      print_hex2chr(adr);             // そのアドレスを表示
    }
    else {
      Serial.print("--");            // 無効表示（--）
    }
  }
  if ( (adr & 0x0F) == 0x0F) {        // 行末なら改行
    Serial.println();
  }
}
 
void print_hex2chr(byte x) {          // 16進2桁で出力
  Serial.print((x >> 4), HEX);       // 上位
  Serial.print((x & 0x0F), HEX);     // 下位
}*/

#include <Wire.h>

unsigned long time1;
unsigned long time2;
unsigned long result;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Wire.requestFrom(8, 1);// スレーブ ID #8に1バイトのデータをリクエスト

  timer();
  while (Wire.available()) {
    byte b = Wire.read(); // データ受け取り
    Serial.println(timer());
    //Serial.println(b);  受け取りデータ
  }

  delay(500);
}

/* 計測関数 */
int timer (){
    static int beforeTime = 0;
    int nowTime = micros();
    int resultTime = nowTime-beforeTime; 
    beforeTime = nowTime;
    return resultTime;
}
