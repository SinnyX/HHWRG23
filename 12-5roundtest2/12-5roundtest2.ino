#include "popx2.h"
#include <QTRSensors.h>
#define NUM_SENSORS 4
#define NUM_SAMPLES_PER_SENSOR 4
#define EMITTER_PIN 2
QTRSensorsAnalog qtra((unsigned char[]){
                        24, 25, 26, 27 },
                      NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];

unsigned long lastReset = 0, timeStateRed = 0, lastResetPID = 0;
int stateTurn = 2, stateRed = 2;
int checkOutLineForTimer = 0;

// int ms = 50;
// float p = 0.03, d = 0.1;
//////////////////////////////
// int ms = 60;
// float p = 0.03, d = 0.2;

//////////////////////////////
int ms = 65;
float p = 0.035, d = 0.2;

void manualCalibrate() {
  qtra.calibrate();
  qtra.calibratedMaximumOn[0] = 974;
  qtra.calibratedMinimumOn[0] = 240;  //
  qtra.calibratedMaximumOn[1] = 981;
  qtra.calibratedMinimumOn[1] = 282;  //
  qtra.calibratedMaximumOn[2] = 987;
  qtra.calibratedMinimumOn[2] = 314;  //
  qtra.calibratedMaximumOn[3] = 982;
  qtra.calibratedMinimumOn[3] = 226;  //
}

int cal_ref(int pin) {
  return (qtra.calibratedMaximumOn[pin] + qtra.calibratedMinimumOn[pin]) / 2;
}
int ref[] = { cal_ref(0), cal_ref(1), cal_ref(2), cal_ref(3) };

void forStart() {
  timer(10, 0.02, 0.01, 10);
  timer(20, 0.02, 0.01, 10);
  timer(30, 0.02, 0.01, 10);
  timer(40, 0.02, 0.01, 10);
}

void setup() {
  setTextSize(2);
  manualCalibrate();

  while (!sw_1()) {
    // viewSensor();
    //   conditionGreen();
    //   if (analog(0) < 300 && analog(3) < 300) {
    //     glcd(4, 0, "C");
    //   } else {
    //     glcd(4, 0, " ");
    //   }
    //   if (stateTurn == 0) {
    //     glcd(4, 5, "L ");
    //   } else if (stateTurn == 1) {
    //     glcd(4, 5, "R ");
    //   } else if (stateTurn == 3) {
    //     glcd(4, 5, "U ");
    //   } else {
    //     glcd(4, 5, "F ");
    //   }
    //   // viewSensor();
  }
  // stateTurn = 2;
  // glcdClear();
  // while (!sw_1())
  // ;
  // sound(1000, 500);
  delay(500);
  // OK();
  forStart();
}

void loop() {
  LineMainPart();
}

extern volatile unsigned long timer0_millis;
void timer(int ms, float kp, float kd, unsigned long period) {
  timer0_millis = 0;
  while (millis() < period) {
    pid(ms, kp, kd);
  }
}