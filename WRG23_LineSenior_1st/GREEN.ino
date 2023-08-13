int sensorAnalog(int pin) {
  return constrain(map(analog(pin), set_min_Analog[pin], set_max_Analog[pin], 100, 0), 0, 100);
}

////////////////////////////////////////////////////
// 0 1 2 3
// L R F U
////////////////////////////////////////////////////
int cgper = 60;
void conditionGreen() {
  if (sensorAnalog(0) > 80 && sensorAnalog(1) > 80) {
    stateTurn = 3;  //Uturn
  } else if (sensorAnalog(0) > cgper) {
    stateTurn = 0;  //Left
  } else if (sensorAnalog(1) > cgper) {
    stateTurn = 1;  //Right
  } else {
    stateTurn = 2;
  }
}