int set_min_Analog[] = { 600, 600 };
int set_max_Analog[] = { 2300, 3600 };

int sensorAnalog(int pin) {
  return constrain(map(analog(pin), set_min_Analog[pin], set_max_Analog[pin], 100, 0), 0, 100);
}

void conditionGreen() {
  if (sensorAnalog(0) > 80 && sensorAnalog(1) > 80) {
    stateTurn = 3;  //Uturn
  } else if (sensorAnalog(0) > 30) {
    stateTurn = 0;  //Left
  } else if (sensorAnalog(1) > 30) {
    stateTurn = 1;  //Right
  } else {
    stateTurn = 2; //Forward
  }
}