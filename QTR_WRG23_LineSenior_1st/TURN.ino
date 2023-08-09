void moveRobot(int speed1, int speed2) {
  motor(1, speed1);
  motor(2, speed2);
}

void L() {
  moveRobot(-100, 80);
  delay(60);
  while (ADD_0.read(0) > ref[0]) {
    moveRobot(-25, 15);
  }
  moveRobot(100, -100);
  delay(10);
  AO();
  delay(1);
}

void R() {
  moveRobot(80, -100);
  delay(60);
  while (ADD_0.read(7) > ref[1]) {
    moveRobot(15, -25);
  }
  moveRobot(-100, 100);
  delay(10);
  AO();
  delay(1);
}

void U() {
}