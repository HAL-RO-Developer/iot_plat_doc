#include <SoftwareSerial.h> // SoftwareSerial.h

// ポート指定 送信側
SoftwareSerial mySerial(D1, D2); // 受信側 RX, TX

char input[100]; //文字列格納用
int i = 0;  // 文字数のカウンタ

void setup() {
  mySerial.begin(115200); // ソフトウェアシリアルを準備
  mySerial.println("Ready");
  Serial.begin(115200); // ハードウェアシリアルの初期化
  Serial.println("OK");
}// setup

void loop() {
  // データ受信した時
  if(mySerial.available()){
      input[i] = mySerial.read();
      // 文字数が30以上 or 末尾文字
      if (i > 30 || input[i] == '.') {
        // 末尾に終端文字の挿入
        input[i] = '\0';
        // 送信
        mySerial.print("送信 >> ");
        mySerial.print(input);
        mySerial.print("\n");
        // 受信
        Serial.print("受信 >> ");
        Serial.print(input);
        Serial.print("\n");
        // カウンタ初期化
        i = 0;
    }
    else { i++; }
  }
}// loop
