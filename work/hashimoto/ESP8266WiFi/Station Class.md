# ESP8266WiFi.h
<ESP8266WiFi.h>にはESP8266WiFiライブラリが含まれています。
このライブラリは、ネットワークに接続するために呼び出すESP8266固有のWi-Fiルーチンを提供します。
Wi-Fiへの接続は、次の呼び出しによって初期化され関数を使います。
WiFi.begin("network-name", "pass-to-network");
network-nameは接続先のSSID、pass-to-networkは接続先のパスワードです。

接続には時間がかかるので下記のようにループで回します
while (WiFi.status() != WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}
WiFi.status()がWL_CONNECTEDを返すと接続が完了です

Serial.println(WiFi.localIP());を使うと
DHCPによってESPモジュールに割り当てられたIPアドレスをSirial出力できます。

## Station class
Station classには、Wi-Fi接続の管理を容易にするためのいくつかの機能があります。接続が失われた場合、再度使用可能になると、ESP8266は最後に使用したアクセスポイントに自動的に再接続します。

## Scan class
範囲内の利用可能なネットワークのスキャン機能およびリスト機能がある

## UDP class
UDPメッセージの送受信を可能にします。 UDPは、データの完全性のチェックサムと、データグラムの送信元と送信先の異なる機能を扱うためのポート番号を提供します。
