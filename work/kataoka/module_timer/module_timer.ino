/*
 * モジュール応答時間計測プログラム
 */

void setup() {
}

void loop() {
  timer(); // モジュール実行前に呼び出す

  /*
   * モジュール実行処理
   */
   
  Serial.println(timer()); // モジュール実行後に結果をシリアルモニターに表示
  
}

/* 計測関数 */
int timer (){
  static int beforeTime = 0;
  int nowTime = micros();
  int resultTime = nowTime-beforeTime; 
  beforeTime = nowTime;
  return resultTime;
}
