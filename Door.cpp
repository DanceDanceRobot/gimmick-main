#include "Door.h"
#include <Arduino.h>
#include <ESP32Servo.h>

Door::Door(Servo* servo1, Servo* servo2, Sonic sonic) : 
  servo1_(servo1), servo2_(servo2), sonic_(sonic), state_(states::WAITING) {}

void Door::execute() {
  static double counter = 0;
  switch(state_) {
    case states::WAITING:
      if (sonic_.distanceCm() < 10) {
        state_ = states::MOVING;
        counter = 0;
      }
      break;
    case states::MOVING:
      counter += 1; // ここの値を変えればドアの動くスピードが変わるよ
      if (counter > 90) {
        state_ = states::FINISHED;
      }
      servo1_->write((int)(90 + counter));
      servo2_->write((int)(90 - counter));
      break;
    case states::FINISHED:
      break;
  }
}

void Door::openDoor() {
  servo1_->write(0);
  servo2_->write(180);
}

void Door::closeDoor() {
  servo1_->write(90);
  servo2_->write(90);
}
