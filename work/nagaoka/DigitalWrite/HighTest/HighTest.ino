// HighTest.ino
// DegitalWriteでHighを出力
// 引数:なし
// 戻り値:なし
// Created 2017/07/12
// By Hirotaka Nagaoka

// includeファイル
#include <DeviceControl.h>\
// 定数定義
#define LED_PIN 16          // LED
#define LED_HIGH HIGH       // High
#define LED_LOW LOW         // Low
#define SET_OUTPUT OUTPUT   // Output
#define SET_INPUT INPUT     // Input

// Setup
void setup( ) {
  // 出力設定
  Digital::SetMode( LED_PIN, SET_OUTPUT );
}

// loop
void loop( ) {
  // High出力
  Digital::Write( LED_PIN, LED_HIGH );
  // Low出力
//  Digital::Write( LED_PIN, LED_LOW );
}
