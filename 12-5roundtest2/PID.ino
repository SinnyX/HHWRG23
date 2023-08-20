
int sensor(int pin) {
  return constrain(map(analog(pin), qtra.calibratedMaximumOn[pin], qtra.calibratedMinimumOn[pin], 100, 0), 0, 100);
}

int error, power_motor, lastError, leftMotorSpeed, rightMotorSpeed;
void pid(int ms, float p, float d) {
  unsigned int position = qtra.readLine(sensorValues, 1, 1);
  error = position - 1500;

  // // conditionRed();
  // if (sensor(0) < 50 || sensor(1) < 50 || sensor(2) < 50 || sensor(3) < 50) {
  //   if (lastError > -800 && lastError < 800) {
  //     if (checkOutLineForTimer == 0) {
  //       lastResetPID = millis();
  //       checkOutLineForTimer++;
  //     }
  //     // if (millis() - lastResetPID < 200 && stateRed == 0) {
  //     //   error = 1800;
  //     // } else if (millis() - lastResetPID < 200 && stateRed == 1) {
  //     //   error = 1300;
  //     // } else
  //     if (millis() - lastResetPID < 50 && stateRed == 2) {
  //       error = 1500;
  //     }
  //   }
  // } else {
  //   if (checkOutLineForTimer != 0) {
  //     checkOutLineForTimer = 0;
  //   }
  // }

  power_motor = (error * p) + ((error - lastError) * d);
  lastError = error;

  leftMotorSpeed = constrain(ms + power_motor, -100, 100);
  rightMotorSpeed = constrain(ms - power_motor, -100, 100);

  if (leftMotorSpeed > 80) {
    leftMotorSpeed = 80;
  }
  if (rightMotorSpeed > 80) {
    rightMotorSpeed = 80;
  }

  // if(leftMotorSpeed < 15){
  //   leftMotorSpeed = -20;
  // }
  // if(rightMotorSpeed < 15){
  //   rightMotorSpeed = -20;
  // }

  motor(1, leftMotorSpeed);
  motor(2, rightMotorSpeed);
}