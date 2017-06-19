#include <ESP8266WiFi.h>

char toSSID[] = "riku'siPhone";//接続先SSID
char ssidPASSWD[] = "Rikuh9212";//接続先のパスワード

void setup() {
  //デバッグ用にシリアルを開く
  Serial.begin(115200);
  Serial.println("PG start");

 

  //WiFiクライアントモード設定
  WiFi.mode(WIFI_STA);


  //WiFiの設定を入れる。IPは、デフォルトがDHCPのようで、IPが共有されるときはWiFiのアクセス情報だけでOK
  WiFi.begin(toSSID, ssidPASSWD);


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
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
    Serial.print("SSID: ");
  Serial.println(WiFi.SSID());//SSID
    Serial.print("Password: ");
  Serial.println(WiFi.psk());//Wi-FiのPassword
Serial.printf("RSSI: %d dBm\n", WiFi.RSSI());//Wifiの強度
Serial.printf("BSSID: %s\n", WiFi.BSSIDstr().c_str());//接続先(ルーター)のMacアドレス

}

void loop() {
 
}
