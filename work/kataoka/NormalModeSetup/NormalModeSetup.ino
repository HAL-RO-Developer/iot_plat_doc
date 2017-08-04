#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include <Wire.h>

typedef struct{
    String ssid;
    String pass;
    String host;
    String port;
    String uuid;
}WIFICONFIG;

WIFICONFIG config;

ESP8266WebServer server( 80 );

/* Wifi接続関数 */
void setupWiFi() {
  /* ルーターに接続 */

  /* エラー時の処理 */
  
}

void statusLamp(int state){
  // 正常時

  // 通信エラー時

  // WiFi接続エラー時
  
}

void setup() {
  int state; // 接続状態

  setupWiFi();

  /* サーバーに接続 */

  statusLamp(state);
}
