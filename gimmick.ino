/*
 * ギミックの回路を制御するためのプログラム
 * by Yota Dori
 * Sep.2023
 * 
 * 質問などは@道理洋太まで。
 */

#include "Sonic.h"
#include "Motor.h"
#include "Kaitenban.h"
#include "Door.h"
#include <ESP32Servo.h>

// スイッチはノーマルオープンでプルアップとする
#define LIMIT1 4
#define LIMIT2 16
#define LIMIT3 21

// 超音波センサをつないでいるピンを設定する
// echo, trigの順番
Sonic sonic1{14, 27};
Sonic sonic2{0, 2};
Sonic sonic3{35, 15};
Sonic sonic4{23, 22};

// モータ
Motor motor1(19, 17);
Motor motor2(18, 5);
Motor motor3(33, 32);

// サーボ
Servo servo1;
Servo servo2;


// 回転板
Kaitenban kaitenban1(motor1, sonic1, LIMIT1);
Kaitenban kaitenban2(motor2, sonic2, LIMIT2);
Kaitenban kaitenban3(motor3, sonic3, LIMIT3);

// ドア
Door door(&servo1, &servo2, sonic4);

void setup() {
  // サーボをつないでいるピンを設定
  servo1.attach(13);
  servo2.attach(12);

  // 初めはドアを閉じる
  door.closeDoor();
  
  Serial.begin( 115200 );//Arduino Unoは9600,ESPで試す場合はは115200
  Serial.println("start");
}

// メインループ 
void loop() {
  // 回転板
  kaitenban1.execute();
  kaitenban2.execute();
  kaitenban3.execute();
  
  // ドア
  door.execute();

  delay(10);
}
