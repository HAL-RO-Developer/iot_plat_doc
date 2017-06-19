#include <ESP8266WiFi.h>

char toSSID[] = "riku'siPhone";//接続先SSID
char ssidPASSWD[] = "Rikuh9212";//接続先のパスワード

void setup() {
  //デバッグ用にシリアルを開く
  Serial.begin(115200);
  Serial.println("PG start");

 

  //WiFiクライアントモード設定
  WiFi.mode(WIFI_STA);

  //WiFiを繋ぐ前に、WiFi状態をシリアルに出力
  WiFi.printDiag(Serial);

  //WiFiの設定を入れる。IPは、デフォルトがDHCPのようで、IPが共有されるときはWiFiのアクセス情報だけでOK
  WiFi.begin(toSSID, ssidPASSWD);


  //接続が確立するまで、・・・を表示
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");

    //WiFi.printDiag(Serial);

  }

  //ここに来たら、接続完了している。

  //改行して繋がったことをシリアルで伝える。
  Serial.println("");
  Serial.println("WiFi connected");

  //WiFiの状態を表示
  WiFi.printDiag(Serial);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());



}

void loop() {
 
}
