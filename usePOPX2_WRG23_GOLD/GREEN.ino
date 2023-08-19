
int set_min_Analog[] = { 0, 0, 0, 0, 268, 322 };
int set_max_Analog[] = { 0, 0, 0, 0, 986, 992 };
int sensorAnalog(int pin) {
  return constrain(map(analog(pin), set_min_Analog[pin], set_max_Analog[pin], 100, 0), 0, 100);
}

////////////////////////////////////////////////////
// 0 1 2 3
// L R F U
////////////////////////////////////////////////////
int cgper = 60;
void conditionGreen() {
  if (sensorAnalog(4) > 80 && sensorAnalog(5) > 80) {
    stateTurn = 3;  //Uturn
  } else if (sensorAnalog(4) > cgper) {
    stateTurn = 0;  //Left
  } else if (sensorAnalog(5) > cgper) {
    stateTurn = 1;  //Right
  } else {
    stateTurn = 2;
  }
}