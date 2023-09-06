#include "Motor.h"
#include "Sonic.h"
#include "Kaitenban.h"
#include <Arduino.h>

Kaitenban::Kaitenban(Motor motor, Sonic sonic, int limitPin):
    motor_(motor), sonic_(sonic), limitPin_(limitPin), state_(states::WAITING) {
  pinMode( limitPin_, INPUT );
}

void Kaitenban::execute() {
  switch(state_) {
    case states::WAITING:
      if (sonic_.distanceCm() < 10) {
        state_ = states::MOVING;
        motor_.startMotor();
        delay(100);
      }
      break;
    case states::MOVING:
      if (digitalRead(limitPin_) == LOW) {
        state_ = states::FINISHED;
        motor_.stopMotor();
        delay(500);
      }
      break;
    case states::FINISHED:
      if (sonic_.distanceCm() > 10) {
        state_ = states::WAITING;
        delay(500);
      }
      break;
    
  }
}
