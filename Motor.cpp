#include "Motor.h"
#include <Arduino.h>

Motor::Motor(int in1, int in2):
    in1_(in1), in2_(in2), moving_(false) {
  pinMode( in1_, OUTPUT );
  pinMode( in2_, OUTPUT );
  digitalWrite(in1_, LOW);
  digitalWrite(in2_, LOW);  
}

void Motor::startMotor() {
  digitalWrite(in1_, LOW);
  digitalWrite(in2_, HIGH);
  moving_ = true;
}

void Motor::stopMotor() {
  digitalWrite(in1_, HIGH);
  digitalWrite(in2_, HIGH);
  moving_ = false;
}

bool Motor::isMoving() {
  return moving_;
}
