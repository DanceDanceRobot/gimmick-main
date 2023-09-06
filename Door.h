//Door.h
#ifndef DOOR_H_INCLUDE
#define DOOR_H_INCLUDE

#include "Sonic.h"
#include <Arduino.h>
#include <ESP32Servo.h>

// ドアを制御するクラス
class Door {
  public:
    // サーボ2つと超音波センサ
    Door(Servo* servo1, Servo* servo2, Sonic sonic);

    // 毎ループ呼ぶ
    void execute();

    // ドアを開ける
    void openDoor();
    
    // ドアを閉める
    void closeDoor();
    
  private:
    // 状態
    enum class states {
      WAITING, // 待機
      MOVING, // 動作中
      FINISHED // 動作終了後
    };
    states state_;
  
    Servo *servo1_;
    Servo *servo2_;
    Sonic sonic_;    
};

#endif
