//Sonic.h
#ifndef SONIC_H_INCLUDE
#define SONIC_H_INCLUDE

// 超音波センサのためのクラス
class Sonic {
  public:
    // エコー、トリガ（ピン2つ）
    Sonic(int echoPin, int trigPin);

    // 距離をcm単位で返す
    double distanceCm();
    
  private:
    int echoPin_;
    int trigPin_;
};

#endif
