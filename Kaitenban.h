//Kaitenban.h
#ifndef KAITENBAN_H_INCLUDE
#define KAITENBAN_H_INCLUDE

#include "Motor.h"
#include "Sonic.h"
#include <Arduino.h>

// 回転板を制御するためのクラス
class Kaitenban {
  public:
    // モータ、超音波センサ、リミットスイッチ
    Kaitenban(Motor motor, Sonic sonic, int limitPin);

    // 毎ループ呼ぶ
    void execute();
    
  private:
    enum class states {
      WAITING, // 待機中
      MOVING, // 回転中
      FINISHED // 90度回ったあと
    };
  
    Motor motor_;
    Sonic sonic_;
    int limitPin_;
    states state_;
    
};

#endif
