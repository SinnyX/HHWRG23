void LineMainPart() {
  if (ADD_0.read(0) < ref[0] && ADD_0.read(7) < ref[7]) {
    conditionGreen();
    lastReset = millis();
    while (millis() - lastReset < 50) {
      pid(ms, p, d);
    }

    if (stateTurn == 0) {
      L();
    } else if (stateTurn == 1) {
      R();
    } else if (stateTurn == 3) {
      U();
    }

    // AO();
    // oled.clear();
    // numberToStringStateTurn();
    // oled.show();
    // if (stateTurn == 0) {
    //   sound(C_5, 300);
    // } else if (stateTurn == 1) {
    //   sound(G_5, 300);
    // } else if (stateTurn == 3) {
    //   sound(C_7, 300);
    // }
    // beep();
    // delay(500);

    // waitSW_OK_bmp();
    // delay(500);
  } else {
    // conditionGreen();
    pid(ms, p, d);
  }
}