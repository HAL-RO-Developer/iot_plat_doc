# Station Class
## begin
特定のアクセスポイントに接続できます。
WiFi.begin("ssid", "pas");
ssidは接続先のSSID、pasはそのパスワード

## config
DHCPを無効にし、IP構成をユーザー定義の任意の値に設定します。
WiFi.config(local_ip, gateway, subnet, dns1, dns2);
local_ipは割り当てるIPアドレス
gatewayは外部ネットワークにアクセスするためのゲートウェイ（ルータ）のIPアドレス
subnetはローカルネットワークのIPアドレスの範囲を定義するマスクです
dns1、dns2はDNSのIPアドレスを定義するオプションのパラメータ。（ないならなくてもいい）

## reconnect
再接続を行います。 これは、アクセスポイントから切断し、次に同じAPに接続を開始することによって行われます。
WiFi.reconnect();

## disconnect
現在設定されているSSIDとパスワードをNULLに設定し、アクセスポイントから切断します。
WiFi.disconnect(wifioff);
wifioffはオプションのブール値パラメータです。 trueに設定すると、ステーションモードはオフになります。

## isConnected
アクセスポイントに接続されている場合はtrue、そうでない場合はfalseを返します。
WiFi.isConnected();

## setAutoConnect
最後に使用したアクセスポイントに電源が投入されると自動的に接続するように設定します。
WiFi.setAutoConnect(autoConnect);
autoConnectはオプションのパラメータで、falseに設定すると自動接続が無効になります。 省略またはtrueに設定すると、自動接続が有効になります。
注：ESPマイコンがすでに切断されているときにsetAutoReconnect（true）を実行しても、アクセスポイントに再接続されない
代わりに、reconnect（）を使用する必要があります。

## waitForConnectResult
ESPマイコンがアクセスポイントに接続するまで待ちます。
WiFi.waitForConnectResult();

## macAddress
MACアドレスを取得します。
WiFi.macAddress(mac);
 - 使用例
  uint8_t macAddr[6];
  WiFi.macAddress(macAddr);

## localIP
マイコンのIPアドレスを返す。
WiFi.localIP();

## subnetMask
subnetMaskを返す。
WiFi.subnetMask();

## gatewayIP
ゲートウェイのIPアドレスを取得
WiFi.gatewayIP();

## dnsIP
DNSのIPアドレスを取得します。
WiFi.dnsIP(dns_no);
入力パラメータdns_noを使用して、必要なドメインネームサーバのIPを指定することができます。
このパラメータはゼロに基づいており、許可される値はnone、0または1です。パラメータが指定されていない場合、DNS＃1のIPが返されます

## hostname
ESPに割り当てられたDHCPホスト名を取得します。
WiFi.hostname();
文字列型を返します。
デフォルトのホスト名はESP_24xMAC形式です。24xMACはモジュールのMACアドレスの最後の24ビットです。
ホスト名は、次の関数を使用して変更できます。
WiFi.hostname(aHostname);
aHostnameは、char * 、const char * またはStringの型です。
最大長は32文字です。
結果に応じてtrueまたはfalseを返します。
たとえば、32文字の制限を超えた場合、関数は新しいホスト名を割り当てずにfalseを返します。

## status
Wi-Fi接続の状態を返す。
WiFi.status();
状態は以下のように返される
WL_CONNECTED：WiFiネットワークに接続されている場合に割り当てられます。
WL_NO_SHIELD：WiFiシールドが存在しない場合に割り当てられます。
WL_IDLE_STATUS：WiFi.begin（）が呼び出されたときに割り当てられる一時的なステータスで、試行回数が終了するか接続が確立されるまで有効です。
WL_NO_SSID_AVAIL：利用可能なSSIDがないときに割り当てられます。
WL_SCAN_COMPLETED：スキャンネットワークが完了したときに割り当てられます。
WL_CONNECT_FAILED：すべての試行で接続が失敗したときに割り当てられます。
WL_CONNECTION_LOST：接続が失われたときに割り当てられます。
WL_DISCONNECTED：ネットワークから切断されたときに割り当てられます。

## SSID
接続先のSSIDを返す
WiFi.SSID();

## psk
接続してるWi-Fiのパスワードを返す
WiFi.psk();

## BSSID
ESPモジュールが接続されているアクセスポイントのMACアドレスを返します。

## RSSI
Wifiの強度を返す。
WiFi.RSSI();
