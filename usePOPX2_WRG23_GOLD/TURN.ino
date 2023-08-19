void moveRobot(int speed1, int speed2) {
  motor(1, speed1);
  motor(2, speed2);
}

void L() {
  moveRobot(-85, 100);
  delay(10);
  while (analog(0) > 300) {
    moveRobot(-45, 30);
  }
  moveRobot(100, -100);
  delay(10);
  AO();
  delay(1);
}

void R() {
  moveRobot(100, -85);
  delay(10);
  while (analog(3) > 300) {
    moveRobot(30, -45);
  }
  moveRobot(-100, 100);
  delay(10);
  AO();
  delay(1);
}

void U() {
  moveRobot(-100, 45);
  delay(220 + 20);
  while (analog(3) > 300) {
    moveRobot(-25, 15);
  }
  moveRobot(100, -100);
  delay(13);
  AO();
  delay(1);
}