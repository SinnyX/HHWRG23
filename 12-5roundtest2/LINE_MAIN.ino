void LineMainPart() {
  if (analog(0) < 400 && analog(3) < 400) {
    // delay(20-10);
    delay(7);
    conditionGreen();

    // if (stateTurn == 2) {
    //   lastReset = millis();
    //   while (millis() - lastReset < 50) {
    //     pid(ms, p, d);
    //   }
    // }

    if (stateTurn == 0) {
      L();
    } else if (stateTurn == 1) {
      R();
    } else if (stateTurn == 3) {
      // lastReset = millis();
      // while (millis() - lastReset < 20) {
      //   fd(50);
      // }
      U();
    }

    // AO();
    // delay(200);
    // glcdClear();
    // numberToStringStateTurn();

    // if (
    //   stateTurn == 0 || stateTurn == 1 || stateTurn == 3) {
      // while (!sw_1())
      //   ;
      // delay(800);
    // }
    forStart();
  } else {
    pid(ms, p, d);
  }
}