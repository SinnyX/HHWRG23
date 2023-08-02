int sensor(int pin) {
  return constrain(map(Data0(pin), set_min[pin], set_max[pin], 100, 0), 0, 100);
}

int Data0[8];
long readline() {
  for (int channel = 0; channel < 8; channel++) {
    Data0[channel] = ADD_0.read(channel);
  }

  int On_line = 0;
  if (sensor(0) > 50 || sensor(1) > 50 || sensor(2) > 50 || sensor(3) > 50 || sensor(4) > 50 || sensor(5) > 50 || sensor(6) > 50 || sensor(7) > 50) {
    On_line = 1;
  } else {
    On_line = 0;
  }
  if (On_line == 1) {
    long A = (sensor(0) * 0 + sensor(1) * 100 + sensor(2) * 200 + sensor(3) * 300 + sensor(4) * 400 + sensor(5) * 500 + sensor(6) * 600 + sensor(7) * 700);
    long B = (sensor(0) + sensor(1) + sensor(2) + sensor(3) + sensor(4) + sensor(5) + sensor(6) + sensor(7));
    Position = (A / B) * 10;  //ทำให้ Position เป็นหลักพัน
    if (checkOutLineForTimer != 0) {
      checkOutLineForTimer = 0;
    }
  } else {
    ////////////////////////////////////////////////////
    if (last_position > 1000 && last_position < 6000) {
      if (checkOutLineForTimer == 0) {
        lastReset = millis();
        checkOutLineForTimer++;
      }
      if (millis() - lastReset < 150) {
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
    // if (last_position < 3500) {
    //   return 0;
    // } else {
    //   return 7000;
    // }

    // if (last_position > 2000 && last_position < 5000) {
    //   return 3500;
    // } else {
    //   return last_position;
    // }
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

  if (leftMotorSpeed > 50) {  // 60 80
    leftMotorSpeed = 50;      // 60 80
  }
  if (leftMotorSpeed < 10) {  // 0 10 ไม่ควรเกิน 15 อย่างมาก 20 มันสั่นง่ายเหวี่ยงง่ายไป
    leftMotorSpeed = -25;     // -35
  }
  if (rightMotorSpeed > 50) {  // 60 80
    rightMotorSpeed = 50;      // 60 80
  }
  if (rightMotorSpeed < 10) {  // 0 10 ไม่ควรเกิน 15 อย่างมาก 20 มันสั่นง่ายเหวี่ยงง่ายไป
    rightMotorSpeed = -25;     // -25
  }

  motor(1, leftMotorSpeed);
  motor(2, rightMotorSpeed);
  // viewPID();

  lastError = error;
}
