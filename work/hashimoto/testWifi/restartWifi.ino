/* Wifiに接続をして完了するとLEDを光らせる（切断されると同じネットワークに再接続 */
#include <ESP8266WiFi.h>

char toSSID[] = "riku'siPhone"; //接続先SSID
char ssidPASSWD[] = "Rikuh9212"; //接続先のパスワード
void setup() {

  //LED用ピンをOUTPUTに設定して、LOWに。
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);

  //WiFiクライアントモード設定
  WiFi.mode(WIFI_STA);
  
  //WiFiの設定を入れる。IPは、デフォルトがDHCPのようで、IPが共有されるときはWiFiのアクセス情報だけでOK
  WiFi.begin(toSSID,ssidPASSWD);
//接続されるまで待つ
   WiFi.waitForConnectResult();
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

 // 切断されたら同じネットワークに再接続
if(WiFi.isConnected() == false){
  WiFi.setAutoConnect(true); //最後に使用したアクセスポイントに電源が投入されると自動的に接続する
  WiFi.waitForConnectResult(); //接続されるまで待つ
}

}
