#include <ESP8266WiFi.h>

char toSSID[] = "riku'siPhone";//接続先SSID
char ssidPASSWD[] = "Rikuh9212";//接続先のパスワード

void setup() {
  //デバッグ用にシリアルを開く
  Serial.begin(115200);
  Serial.println("PG start");

  //WiFiに繋がったらLEDを点灯させるので、そのピンをOUTPUTに設定して、LOWに。
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);

  //WiFiクライアントモード設定
  WiFi.mode(WIFI_STA);

  //WiFiを繋ぐ前に、WiFi状態をシリアルに出力
  WiFi.printDiag(Serial);

  //WiFiの設定を入れる。IPは、デフォルトがDHCPのようで、IPが共有されるときはWiFiのアクセス情報だけでOK
  WiFi.begin(toSSID, ssidPASSWD);

  // 固定IPではネットワークステータスが上手く動かないので、今は使えなさそう。
  // 本家にバグ登録はされているらしい。
  //  WiFi.config(ip, gateway, subnet);

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

  // 無線LAN接続OK LED点灯
  digitalWrite(5, HIGH);


}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    // コネクション確立済み以外のステータスなので
    // 無線LAN接続NG LED消灯
    digitalWrite(5, LOW);
  } else {
    //コネクションOKなので、点灯
    digitalWrite(5, HIGH );
  }

  delay(500);

}
