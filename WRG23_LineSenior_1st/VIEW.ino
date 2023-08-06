void viewPID() {
  oled.text(0, 0, "E = %d     ", adjustError());
  oled.text(1, 0, "P = %d     ", readline());
  oled.text(2, 0, "L = %d     ", leftMotorSpeed);
  oled.text(3, 0, "R = %d     ", rightMotorSpeed);
  viewSensor();
  // oled.show();
}

void viewSensor() {
  for (int i = 0; i < 8; i++) {
    oled.text(i + 4, 0, "%d %d  ", i, sensor(i));
    oled.text(i + 4, 6, "%d   ", ADD_0.read(i));
  }
  oled.text(14, 0, "L %d  ", sensorAnalog(0));
  oled.text(14, 6, "%d   ", analog(0));
  oled.text(15, 0, "R %d  ", sensorAnalog(1));
  oled.text(15, 6, "%d   ", analog(1));
  oled.show();
}

void numberToStringStateTurn() {
  if (stateTurn == 0) {
    oled.text(0, 15, "L");
  } else if (stateTurn == 1) {
    oled.text(0, 15, "R");
  } else if (stateTurn == 3) {
    oled.text(0, 15, "U");
  } else {
    oled.text(0, 15, "F");
  }
}

void viewMinMax() {
  waitSW_OK_bmp();  //ห้ามแก้ไข ยังไม่ทำจนกว่าจะกดปุ่ม OK
  //ฟังก์ชั่นหาค่า min max ของเซ็นเซอร์แบบออโต้
  sound(1000, 1000);               //ห้ามแก้ไข
  oled.textSize(2);                //ห้ามแก้ไข
  oled.clear();                    //ห้ามแก้ไข
  oled.mode(2);
  oled.text(2, 0, "Calibrate..");  //ห้ามแก้ไข
  oled.show();                     //ห้ามแก้ไข
  int minViewValues[10] = { 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095 };
  int maxViewValues[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  for (int i = 0; i < 30000; i++) {
    int sensorViewValue;
    for (int j = 0; j < 11; j++) {
      if (j == 9) {
        sensorViewValue = analog(0);
      } else if (j == 10) {
        sensorViewValue = analog(1);
      } else {
        sensorViewValue = ADD_0.read(j);
      }
      minViewValues[j] = min(minViewValues[j], sensorViewValue);
      maxViewValues[j] = max(maxViewValues[j], sensorViewValue);
    }
  }
  sound(1000, 1000);  //ห้ามแก้ไข
  oled.mode(1);
  oled.textSize(1);
  oled.clear();  //ห้ามแก้ไข

  for (int i = 0; i < 8; i++) {
    oled.text(i, 0, "%d    ", maxViewValues[i]);
    oled.text(i, 6, "%d    ", minViewValues[i]);
  }
  oled.text(8, 1, "A3    A4");
  oled.text(9, 0, "%d  %d", ((maxViewValues[3] + minViewValues[3]) / 2), ((maxViewValues[4] + minViewValues[4]) / 2));

  oled.text(11, 0, "%d    ", maxViewValues[8]);
  oled.text(11, 6, "%d    ", minViewValues[8]);
  oled.text(12, 0, "%d    ", maxViewValues[9]);
  oled.text(12, 6, "%d    ", minViewValues[9]);
  oled.show();
  oled.mode(1);
  waitSW_OK_bmp();
}