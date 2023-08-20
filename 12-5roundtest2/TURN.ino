void moveRobot(int speed1, int speed2) {
  motor(1, speed1);
  motor(2, speed2);
}

// void L() {
//   moveRobot(-85, 100);
//   delay(10);
//   while (analog(0) > 500) {
//     moveRobot(-45, 30);
//   }
//   moveRobot(100, -100);
//   delay(10);
//   AO();
//   delay(1);
// }

void L() {
  moveRobot(-85, 100);
  delay(10);
  while (analog(0) > 500) {
    // moveRobot(-65, 50);
    moveRobot(-55, 40);
  }
  moveRobot(100, -100);
  delay(10);
  AO();
  delay(1);
}

// void R() {
//   moveRobot(100, -85);
//   delay(10);
//   while (analog(3) > 500) {
//     moveRobot(30, -45);
//   }
//   moveRobot(-100, 100);
//   delay(10);
//   AO();
//   delay(1);
// }

void R() {
  moveRobot(100, -85);
  delay(10);
  while (analog(3) > 500) {
    // moveRobot(50, -65);
    moveRobot(40, -55);
  }
  moveRobot(-100, 100);
  delay(10);
  AO();
  delay(1);
}

void U() {
  moveRobot(40, -80);
  delay(220 + 20);
  while (analog(3) > 500) {
    // moveRobot(50, -65);
    moveRobot(30, -45);
  }
  //  moveRobot(100, -85);
  // delay(10);
  // while (analog(3) > 500) {
  //   moveRobot(30, -45);
  // }
  moveRobot(100, -100);
  delay(10);
  AO();
  delay(1);
  // OK();
  // sound(1000, 1000);
}

// void U() {
//   moveRobot(40, -80);
//   delay(220 + 20);
//   while (analog(3) > 500) {
//     moveRobot(15, -25);
//   }
//   //  moveRobot(100, -85);
//   // delay(10);
//   // while (analog(3) > 500) {
//   //   moveRobot(30, -45);
//   // }
//   moveRobot(100, -100);
//   delay(10);
//   AO();
//   delay(1);
//   // OK();
//   // sound(1000, 1000);
// }