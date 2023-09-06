#include "Sonic.h"
#include <Arduino.h>

Sonic::Sonic(int echoPin, int trigPin):echoPin_(echoPin), trigPin_(trigPin) {
  pinMode( echoPin_, INPUT );
  pinMode( trigPin_, OUTPUT );  
}

double Sonic::distanceCm() {
  double distance = 0;
  
  digitalWrite(trigPin_, LOW); 
  delayMicroseconds(2); 
  digitalWrite( trigPin_, HIGH ); //超音波を出力
  delayMicroseconds( 10 ); //
  digitalWrite( trigPin_, LOW );

  double duration = pulseIn( echoPin_, HIGH ); //センサからの入力
  if (duration > 0) {
    duration = duration/2; //往復距離を半分にする
    distance = duration*340*100/1000000; // 音速を340m/sに設定
  }
  return distance;
}
