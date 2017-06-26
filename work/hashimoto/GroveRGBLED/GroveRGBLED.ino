#include <ChainableLED.h> /* http://wiki.seeedstudio.com/wiki/File:Chainable_LED_Library.zip からインストールする*/
unsigned long t1;
unsigned long t2;
ChainableLED led(5, 4, 1);/*インスタンスを生成(引数は左から順に、クロックポート（モジュールの黄色の線を繋いでるポート)、データポート（モジュールの白線を繋いでるポート)、LED接続数を設定します。*/
void setup()
{
  Serial.begin(115200);
}
void loop(){
 t1 = micros();
 led.setColorRGB(0, 255, 0,0); /*引数は左からLED番号(モジュール上のJ1が0),Red0～255,Green0～255,Blue0～255*/
  t2 = micros();
  Serial.println(t2-t1);//表示
 delay(1000);
 led.setColorRGB(0, 0, 255, 0); 
 delay(1000);
led.setColorRGB(0, 0, 0,255); 
delay(1000);
}

