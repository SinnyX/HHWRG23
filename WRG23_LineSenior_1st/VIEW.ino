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
  oled.text(2, 0, "Calibrate..");  //ห้ามแก้ไข
  oled.show();                     //ห้ามแก้ไข
  int minViewValues[5] = { 4095, 4095, 4095, 4095, 4095 };
  int maxViewValues[5] = { 0, 0, 0, 0, 0 };
  for (int i = 0; i < 30000; i++) {
    for (int j = 0; j < 5; j++) {
      int sensorViewValue = analog(j);
      minViewValues[j] = min(minViewValues[j], sensorViewValue);
      maxViewValues[j] = max(maxViewValues[j], sensorViewValue);
    }
  }
  sound(1000, 1000);  //ห้ามแก้ไข
  oled.textSize(1);
  oled.clear();  //ห้ามแก้ไข
  for (int i = 0; i < 5; i++) {
    oled.text(i + 3, 0, "(%d) max %d", i, maxViewValues[i]);
    oled.text(i + 3, 13, "min %d", minViewValues[i]);
  }
  oled.text(0, 4, "Ref = {%d, %d", ((maxViewValues[0] + minViewValues[0]) / 2), ((maxViewValues[1] + minViewValues[1]) / 2));  //ห้ามแก้ไข
  oled.text(1, 4, "%d, %d, %d}", ((maxViewValues[2] + minViewValues[2]) / 2), ((maxViewValues[3] + minViewValues[3]) / 2),
            ((maxViewValues[4] + minViewValues[4]) / 2));  //ห้ามแก้ไข
  oled.show();                                             //ห้ามแก้ไข
  waitSW_OK_bmp();
}