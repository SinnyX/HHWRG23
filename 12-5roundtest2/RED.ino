// void conditionRed() {
//   if (sensor(1) > 50 && sensor(2) > 50
//       && analog(4) > 600 && analog(4) < 700) {
//     stateRed = 0; //L
//     timeStateRed = millis();
//   } else if (sensor(1) > 50 && sensor(2) > 50
//              && analog(5) > 600 && analog(5) < 700) {
//     stateRed = 1; //R
//     timeStateRed = millis();
//   }
//   if (millis() - timeStateRed > 200) {
//     if (stateRed != 2) {
//       stateRed = 2;
//     }
//   }
// }