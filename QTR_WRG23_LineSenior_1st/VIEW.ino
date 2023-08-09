void viewPID() {
  int error = readline();
  oled.text(0, 0, "E = %d     ", error - 2500);
  oled.text(1, 0, "P = %d     ", error);
  oled.text(2, 0, "L = %d     ", leftMotorSpeed);
  oled.text(3, 0, "R = %d     ", rightMotorSpeed);
  viewSensor();
}

void viewSensor() {
  for (int i = 0; i < 6; i++) {
    oled.text(i + 4, 0, "%d %d  ", i + 1, sensor(i));
    oled.text(i + 4, 6, "%d   ", ADD_0.read(i + 1));
  }
  oled.show();
  delay(30);
}

void viewStateTurn() {
  if (stateTurn == 0) {
    oled.text(0, 15, "L");
  } else if (stateTurn == 1) {
    oled.text(0, 15, "R");
  } else if (stateTurn == 3) {
    oled.text(0, 15, "U");
  } else {
    oled.text(0, 15, "F");
  }
  oled.show();
}