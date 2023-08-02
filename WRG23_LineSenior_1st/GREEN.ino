int sensorAnalog(int pin) {
  return constrain(map(analog(pin), set_min_Analog[pin], set_max_Analog[pin], 100, 0), 0, 100);
}

////////////////////////////////////////////////////
// 0 1 2 3
// L R F U
////////////////////////////////////////////////////
void conditionGreen() {
  if (sensorAnalog(0) > 60 && sensorAnalog(1) > 60) {
    stateTurn = 3;  //Uturn
    lastTimeFound = millis();
  } else if (sensorAnalog(0) > 60) {
    // AO();
    // sound(1000, 1000);
    stateTurn = 0;  //Left
    lastTimeFound = millis();
  } else if (sensorAnalog(1) > 60) {
    // AO();
    // sound(1000, 1000);
    stateTurn = 1;  //Right
    lastTimeFound = millis();
  }
  if (millis() - lastTimeFound > 50) {
    if (stateTurn != 2) {
      stateTurn = 2;
    }
  }
}

void TestconditionGreen() {
  if (sensorAnalog(0) > 60 && sensorAnalog(1) > 60) {
    stateTurn = 3;  //Uturn
  } else if (sensorAnalog(0) > 60) {
    stateTurn = 0;  //Left
  } else if (sensorAnalog(1) > 60) {
    stateTurn = 1;  //Right
  } else {
    stateTurn = 2;
  }

  // if (stateTurn == 0) {
  //   oled.text(0, 15, "L");
  // } else if (stateTurn == 1) {
  //   oled.text(0, 15, "R");
  // } else if (stateTurn == 3) {
  //   oled.text(0, 15, "U");
  // } else {
  //   oled.text(0, 15, "F");
  // }
  // oled.show();
}