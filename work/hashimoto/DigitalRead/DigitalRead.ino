// Created 2017/07/14		
// By Riku Hashimoto

// include
#include <DeviceControl.h>
#include <ArduinoJson.h>

//定数定義
# define BTN_pin 5

//setup
void setup() {
  
  Serial.begin(115200);
  Digital::SetMode(BTN_pin, OUTPUT);
  	
}

//loop
void loop() {
 String json =  digitalread(BTN_pin); //デジタル入力の結果を受け取る
 StaticJsonBuffer<200> jsonBuffer;// JSON用の固定バッファを確保する(200文字)
 JsonObject& root = jsonBuffer.parseObject(json); // JsonObjectはJSONBufferに格納、パースされた結果を参照保持する。
// Jsonを型変換する
String result = root["result"];
String pin = root["pin"];
String value = root["value"];
Serial.print(result);
Serial.print( pin);
Serial.println( value);
 delay(1000);//シリアル結果を見やすくするため
}
 
//digitalrea
String digitalread(int pin){
 int val = Digital::Read(pin);
    String resultdata = "OK";
  String pindata = String(pin);
 String valuedata = String(val);
 String rtn = "{\"result\":\"" + resultdata +
                 "\",\"pin\":\"" +pindata +
                 "\",\"value\":\"" +valuedata + 
                 "\"}";
return rtn;
}
