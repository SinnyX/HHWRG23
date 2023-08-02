void moveRobot(int speed1, int speed2) {
  motor(1, speed1);
  motor(2, speed2);
}

void AO_delay() {
  AO();
  delay(200);
}

void L() {
  moveRobot(-100, 80);
  delay(100);
  while (ADD_0.read(4) > ref[4]) {
    moveRobot(-30, 20);
  }
  moveRobot(100, -100);
  delay(40);
  AO();
  delay(1);
}

void R() {
  moveRobot(80, -100);
  delay(100);
  while (ADD_0.read(3) > ref[3]) {
    moveRobot(20, -30);
  }
  moveRobot(-100, 100);
  delay(30);
  AO();
  delay(1);
}

void U() {
  moveRobot(60, -80);
  delay(180);
  while (ADD_0.read(3) > ref[3]) {
    moveRobot(20, -30);
  }
  moveRobot(-100, 100);
  delay(30);
  AO();
  delay(1);
}