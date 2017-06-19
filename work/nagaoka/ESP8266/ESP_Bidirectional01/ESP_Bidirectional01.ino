#include <SoftwareSerial.h> // ソフトウェアシリアル

// ポート指定 送信側
SoftwareSerial mySerial(D1, D2); // 受信側 RX, TX

char input[100]; //文字列格納用
int i = 0;  // 文字数のカウンタ

void setup() {
  Serial.begin(115200); // ハードウェアシリアルを準備
  Serial.println("Ready");
  mySerial.begin(115200); // ソフトウェアシリアルの初期化
  mySerial.println("OK");
}// setup

void loop() {
  // データ受信した時
  if(Serial.available()){
      input[i] = Serial.read();
      // 文字数が30以上 or 末尾文字
      if (i > 30 || input[i] == '.') {
        // 末尾に終端文字の挿入
        input[i] = '\0';
        // 送信
        Serial.print("送信 >> ");
        Serial.print(input);
        Serial.print("\n");
        // 受信
        mySerial.print("受信 >> ");
        mySerial.print(input);
        mySerial.print("\n");
        // カウンタ初期化
        i = 0;
    }
    else { i++; }
  }
}// loop
