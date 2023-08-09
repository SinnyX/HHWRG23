int set_min[] = { 300, 700, 950, 600, 800, 550 };
int set_max[] = { 1000, 1550, 2200, 1500, 2500, 1500 };
long Position, last_position, last_error = 0;
bool timerOutLine = false;
unsigned long lastReset = 0;
int error, power_motor, lastError = 0, leftMotorSpeed, rightMotorSpeed;

int sensor(int pin) {
  return constrain(map(ADD_0.read(pin + 1), set_min[pin], set_max[pin], 100, 0), 0, 100);
}

long readline() {
  int On_line = 0;
  if (sensor(0) > 50 || sensor(1) > 50 || sensor(2) > 50 || sensor(3) > 50 || sensor(4) > 50 || sensor(5) > 50) {
    On_line = 1;
  } else {
    On_line = 0;
  }

  if (On_line == 1) {
    long A = (sensor(0) * 0 + sensor(1) * 100 + sensor(2) * 200 + sensor(3) * 300 + sensor(4) * 400 + sensor(5) * 500);
    long B = (sensor(0) + sensor(1) + sensor(2) + sensor(3) + sensor(4) + sensor(5));
    Position = (A / B) * 10;
    if (timerOutLine == false) {
      timerOutLine = true;
    }
  } else if (last_position > 1500 && last_position < 3500) {
    if (timerOutLine == true) {
      lastReset = millis();
      timerOutLine = false;
    }
    if (millis() - lastReset < 80) {
      return 2500;
    } else if (last_position > 2500 + 150) {
      return 5000;
    } else {
      return 0;
    }
  } else if (last_position < 2500 - 400) {
    return 0;
  } else {
    return 5000;
  }
  return last_position = Position;
}

void pid(int ms, float p, float d) {
  error = readline() - 2500;
  power_motor = (error * p) + ((error - lastError) * d);
  leftMotorSpeed = ms + power_motor;
  rightMotorSpeed = ms - power_motor;
  // if (leftMotorSpeed > 80) {
  //   leftMotorSpeed = 80;
  // }
  if (leftMotorSpeed < 0) {
    leftMotorSpeed = -25;
  }
  // if (rightMotorSpeed > 80) {
  //   rightMotorSpeed = 80;
  // }
  if (rightMotorSpeed < 0) {
    rightMotorSpeed = -25;
  }

  if (error > 2000) {
    leftMotorSpeed = 60;
    rightMotorSpeed = -80;
  }
  if (error < -2000) {
    leftMotorSpeed = -80;
    rightMotorSpeed = 60;
  }
  motor(1, constrain(leftMotorSpeed, -100, 100));
  motor(2, constrain(rightMotorSpeed, -100, 100));
  lastError = error;
}