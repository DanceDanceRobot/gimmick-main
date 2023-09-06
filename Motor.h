//Motor.h
#ifndef MOTOR_H_INCLUDE
#define MOTOR_H_INCLUDE

// モータを制御するためのクラス
class Motor {
  public:
    // ピンは二つ
    Motor(int in1, int in2);
    
    // モータを回す
    void startMotor();
    
    // 回転を止める
    void stopMotor();
    
    // 回転中か
    bool isMoving();
    
  private:
    int in1_;
    int in2_;
    bool moving_;
};

#endif
