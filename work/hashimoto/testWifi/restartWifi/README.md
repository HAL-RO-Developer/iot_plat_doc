# restartWifi.ino
- WiFi.isConnected()
 - アクセスポイントに接続されている場合はtrue、そうでない場合はfalseを返します。
- WiFi.setAutoConnect(true);
 - 最後に使用したアクセスポイントに電源が投入されると自動的に接続する
- WiFi.waitForConnectResult();
 - 接続されるまで待つ
