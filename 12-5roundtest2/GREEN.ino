
int set_min_Analog[] = { 0, 0, 0, 0, 241, 256 };
int set_max_Analog[] = { 0, 0, 0, 0, 986, 993 };
int sensorAnalog(int pin) {
  return constrain(map(analog(pin), set_min_Analog[pin], set_max_Analog[pin], 100, 0), 0, 100);
}

////////////////////////////////////////////////////
// 0 1 2 3
// L R F U
////////////////////////////////////////////////////
int cgper = 40;
void conditionGreen() {
  if (sensorAnalog(4) > 60 && sensorAnalog(5) > 60) {
    stateTurn = 3;  //Uturn
  } else if (sensorAnalog(4) > cgper) {
    stateTurn = 0;  //Left
  } else if (sensorAnalog(5) > cgper) {
    stateTurn = 1;  //Right
  } else {
    stateTurn = 2;
  }
}