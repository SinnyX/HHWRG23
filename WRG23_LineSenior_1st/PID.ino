int Data0[8];
int sensor(int pin) {
  return constrain(map(ADD_0.read(pin), set_min[pin], set_max[pin], 100, 0), 0, 100);
}

int sensor_all(int pin) {
  return constrain(map(Data0[pin], set_min[pin], set_max[pin], 100, 0), 0, 100);
}

long readline() {
  for (int channel = 0; channel < 8; channel++) {
    Data0[channel] = ADD_0.read(channel);
  }

  int On_line = 0;
  if (sensor_all(0) > 50 || sensor_all(1) > 50 || sensor_all(2) > 50 || sensor_all(3) > 50 || sensor_all(4) > 50 || sensor_all(5) > 50 || sensor_all(6) > 50 || sensor_all(7) > 50) {
    On_line = 1;
  } else {
    On_line = 0;
  }
  if (On_line == 1) {
    long A = (sensor_all(0) * 0 + sensor_all(1) * 100 + sensor_all(2) * 200 + sensor_all(3) * 300 + sensor_all(4) * 400 + sensor_all(5) * 500 + sensor_all(6) * 600 + sensor_all(7) * 700);
    long B = (sensor_all(0) + sensor_all(1) + sensor_all(2) + sensor_all(3) + sensor_all(4) + sensor_all(5) + sensor_all(6) + sensor_all(7));
    Position = (A / B) * 10;  //ทำให้ Position เป็นหลักพัน
    if (checkOutLineForTimer != 0) {
      checkOutLineForTimer = 0;
    }
  } else {
    ////////////////////////////////////////////////////
    if (last_position > 3000 && last_position < 4000) {
      if (checkOutLineForTimer == 0) {
        lastReset = millis();
        checkOutLineForTimer++;
      }
      if (millis() - lastReset < 100) {
        return 3500;
      } else {
        if (last_position > 3500) {
          return 7000;
        } else {
          return 0;
        }
      }
    } else if (last_position < 3500) {
      return 0;
    } else {
      return 7000;
    }
    ////////////////////////////////////////////////////
  }
  return last_position = Position;
}

int adjustError() {
  return readline() - 3500;
}

void pid(int ms, float p, float d) {
  error = adjustError();
  power_motor = (error * p) + ((error - lastError) * d);
  leftMotorSpeed = constrain(ms + power_motor, -100, 100);
  rightMotorSpeed = constrain(ms - power_motor, -100, 100);

  if (leftMotorSpeed > 50) {
    leftMotorSpeed = 50;
  }
  // if (leftMotorSpeed < 30) {
  //   leftMotorSpeed = -35;
  // }
  if (rightMotorSpeed > 50) {
    rightMotorSpeed = 50;
  }
  // if (rightMotorSpeed < 30) {
  //   rightMotorSpeed = -35;
  // }

  motor(1, leftMotorSpeed);
  motor(2, rightMotorSpeed);
  // viewPID();

  lastError = error;
}
