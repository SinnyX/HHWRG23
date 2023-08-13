void moveRobot(int speed1, int speed2) {
  motor(1, speed1);
  motor(2, speed2);
}

void AO_delay() {
  AO();
  delay(200);
}

void L() {
  moveRobot(-100, 85);
  delay(80);
  while (ADD_0.read(2) > 1600) {
    moveRobot(-25, 15);
  }
  moveRobot(100, -100);
  delay(10);
  AO();
  delay(1);
}

void R() {
  moveRobot(85, -100);
  delay(85);
  while (ADD_0.read(6) > 1350) {
    moveRobot(15, -25);
  }
  moveRobot(-100, 100);
  delay(10);
  AO();
  delay(1);
}

void U() {
  moveRobot(-100, 45);
  delay(220);
  while (ADD_0.read(3) > 1675) {
    moveRobot(-25, 15);
  }
  moveRobot(100, -100);
  delay(13);
  AO();
  delay(1);
}