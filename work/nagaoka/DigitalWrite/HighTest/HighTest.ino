// HighTest.ino
// DegitalWrite
// 引数:なし
// 戻り値:なし
// Created 2017/07/12
// By Hirotaka Nagaoka

// includeファイル
#include <DeviceControl.h>
// 定数定義
#define LED_PIN 16          // LED
#define LED_HIGH HIGH       // High
#define LED_LOW LOW         // Low
#define SET_OUTPUT OUTPUT   // Output
#define SET_INPUT INPUT     // Input

// Setup
void setup( ) {}

// loop
void loop( ) {
  digiWrite( LED_PIN, SET_OUTPUT, LED_HIGH );
}

int digiWrite( int pin, int output, int val ){
  Digital::SetMode( pin, output );
  Digital::Write( pin, val );
}

