void numberToStringStateTurn() {
  if (stateTurn == 0) {
    glcd(4, 4, "L");
  } else if (stateTurn == 1) {
    glcd(4, 4, "R");
  } else if (stateTurn == 3) {
    glcd(4, 4, "U");
  } else {
    glcd(4, 4, "F");
  }
}

void viewSensor() {
  for (int i = 0; i < 4; i++) {
    glcd(i, 0, "%d %d  ", i, sensor(i));
    glcd(i, 6, "%d   ", analog(i));
  }
  glcd(5, 0, "L %d  ", sensorAnalog(4));
  glcd(5, 6, "%d   ", analog(4));
  glcd(6, 0, "R %d  ", sensorAnalog(5));
  glcd(6, 6, "%d   ", analog(5));
}
