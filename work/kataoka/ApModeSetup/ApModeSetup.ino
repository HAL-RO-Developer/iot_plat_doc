#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include <Wire.h>

const   SCHR*   ap_ssid     = "ESP8266";  /* デバイスのSSID */
const   SCHR*   ap_pass     = "password"; /* デバイスのパスワード */

typedef struct{
    String ssid;
    String pass;
    String host;
    String port;
    String uuid;
}WIFICONFIG;

WIFICONFIG config;

ESP8266WebServer server( 80 );


void setup() {
  /* 入力フォーム表示 */
  inputForm();

  /* 入力データを内部メモリに保存 */
  savedInput();
}

/* 入力フォーム関数 */
void inputForm(){
  
}

/* データ保存関数 */
void savedInput(){
  
}
