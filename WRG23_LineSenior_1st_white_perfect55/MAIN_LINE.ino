// int pj = 0;
void LineMainPart() {
  if (ADD_0.read(0) < ref[0] && ADD_0.read(7) < ref[7]) {
  // if (ADD_0.read(1) < ref[1] && ADD_0.read(6) < ref[6]) {
    delay(7 - 2);
    conditionGreen();
    // AO();
    // beep();
    // delay(200);

    // if (stateTurn == 2) {
      // lastReset = millis();
      // while (millis() - lastReset < 80) {
      //   // fd(60);
      //   pid(ms, p, d);
      // }
    // }

    if (stateTurn == 0) {
      L();
    } else if (stateTurn == 1) {
      R();
    } else if (stateTurn == 3) {
      lastReset = millis();
      while (millis() - lastReset < 20) {
        fd(50);
      }
      U();
      // waitSW_OK_bmp();
      // delay(500);
    }

    // AO();
    // oled.clear();
    // numberToStringStateTurn();
    // oled.show();
    // if (stateTurn == 0) {
    // sound(C_5, 300);
    // } else if (stateTurn == 1) {
    // sound(G_5, 300);
    // } else if (stateTurn == 3) {
    // sound(C_7, 300);
    // }
    // beep();
    // delay(500);

    // pj++;
    // if (pj > 1) {
    // AO();
    // waitSW_OK_bmp();
    //   pj = 0;
    // delay(500);
    // }

    // if (
    //   // stateTurn == 0 || 
    //   // stateTurn == 1 || 
    //   stateTurn == 3) {
    //   AO();
    //   delay(1);
    //   waitSW_OK_bmp();
    //   delay(500);
    // }
  } else {
    pid(ms, p, d);
  }
}