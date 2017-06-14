/* Wifiに接続をして完了するとLEDを光らせる（切断されると同じネットワークに再接続 */
#include <ESP8266WiFi.h>

char toSSID[] = "riku'siPhone"; //接続先SSID
char ssidPASSWD[] = "Rikuh9212"; //接続先のパスワード
 int flg = 0;
void setup() {
  //デバッグ用にシリアルを開く
  Serial.begin(115200);
  Serial.println("PG start");

  //LED用ピンをOUTPUTに設定して、LOWに。
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);

  //WiFiクライアントモード設定
  WiFi.mode(WIFI_STA);

  //WiFiを繋ぐ前に、WiFi状態をシリアルに出力
  WiFi.printDiag(Serial);

  //WiFiの設定を入れる。IPは、デフォルトがDHCPのようで、IPが共有されるときはWiFiのアクセス情報だけでOK
  WiFi.begin(toSSID,ssidPASSWD);

  //接続が確立するまで、・・・を表示
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");

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
    flg = 0;
  }
  
 // 切断されたら同じネットワークに再接続
if(WiFi.isConnected()== false && flg == 0){
  WiFi.begin(toSSID,ssidPASSWD);
  flg = 1;
}

}
