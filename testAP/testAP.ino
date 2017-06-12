// includeファイル
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>

// ssidとパスワードの設定
static const char *ssid = "esp8266";
static const char *pwd = "8266";

// サーバーポートの指定
ESP8266WebServer server(80); 
// IPアドレス
IPAddress ip( 192, 168, 128, 21); 
// サブネットマスク
IPAddress subnet( 255, 255, 255, 0 );

// htmlファイルの読み込み場所
String strIndexHtml;
// ボタンの状態管理
boolean flagGod;

// indexページ
void handleRoot() {

    Serial.println("receive req: /");
    // Postの場合、パラメータからフラグを設定
    if (server.method() == HTTP_POST) {
      String s = server.arg("FLAG");
      if (s == "1") {
        flagGod = true;
      } else {
        flagGod = false;
      }
    }
    // テンプレートのindexページ文字列をフラグによって設定
    String msg = "";
    if (!flagGod) {
      msg = "チェンジ・プライベートモード";
    } else {
       msg = "チェンジ・ビジネスモード！";
    }
    String arg1 = "${submit_msg}";
    String tmpl = "" + strIndexHtml;
    tmpl.replace(arg1, msg);
    tmpl.replace("${flag}", flagGod ? "0" : "1");
    tmpl.replace("${img}", flagGod ? "/img2.gif" : "/img1.gif");
    Serial.println(tmpl);

    // クライアントに返す
    server.send(200, "text/html", tmpl);

}

// /img1.gifハンドラ
void handleImg1() {
    Serial.println("receive req: /img1.gif");
    // リソースから読み込んで画像をかえす。
    SPIFFS.begin();
    File hogeFile = SPIFFS.open("/images.png", "r");
    // バイナリのリソースを返すならこんな感じ。
    server.streamFile(hogeFile, "image/gif");
    hogeFile.close();
}
// /img2.gifハンドラ
void handleImg2() {
    Serial.println("receive req: /img2.gif");

    // リソースから読み込んで画像をかえす。
    SPIFFS.begin();
    File hogeFile = SPIFFS.open("/images-2.png", "r");
    // バイナリのリソースを返すならこんな感じ。
    server.streamFile(hogeFile, "image/gif");
    hogeFile.close();
}

// テキストファイルを読み込み
String loadTextFile(String path) {
  String txt = "";
  String line = "";
  char c;
  File hogeFile = SPIFFS.open(path, "r");
    strIndexHtml = "";
  if (hogeFile) {
    Serial.println("file open success...");

    while (hogeFile.available()) {
      // １文字読み込み
      c = hogeFile.read();
      // 改行の場合
      if (c == '\n' || c == '\r') {
        // 行文字列の長さが１以上の場合
        if (line.length() > 0) {
          txt = txt + line + "\n";
          //Serial.println(line);
        }
        // 改行文字が来たので行文字列をクリア
        line = "";
      } else {
        // 改行文字でなければ行文字列に読み込んだ1文字を追加
        line = line + String(c);       
      }
    }
    if (line.length() > 0) {
      txt = txt + line;
    }

    hogeFile.close();
  } else {
    Serial.println("file open failed...");
  }
  Serial.println(path + " is loaded...");

  return txt;
}


// リソース読み込み
void loadHtmlResource() {

  String line = "";
  char c;

  SPIFFS.begin();
//  Dir dir = SPIFFS.openDir("/");
//  while (dir.next()) {
//    Serial.print(dir.fileName());
//    File f = dir.openFile("r");
//    Serial.println(String(" ") + f.size());
//  }

  strIndexHtml = loadTextFile("/index.html");
}

/* 設定 */
void setup() {
  flagGod = false;
  Serial.begin(9600);
  WiFi.mode(WIFI_AP); 
  WiFi.softAPConfig(ip, ip, subnet); 
  WiFi.softAP(ssid, pwd); 

  // ハンドラ設定
  server.on("/", handleRoot); 
  server.on("/img1.gif", handleImg1);
  server.on("/img2.gif", handleImg2); 

  server.begin();
  Serial.println("ap setup..."); 
  loadHtmlResource();
  Serial.println(strIndexHtml);
  Serial.println("load complete...");
} 
void loop() { 
  server.handleClient(); 
}

