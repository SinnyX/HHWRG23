#include <POP32.h>
#include <ADS7828.h>

#define OPEN 2
#define SENIOR 1
int useRobot = OPEN;
///////////////////////////////////////////////////////////////////
int set_min[] = { 1000, 850, 990, 1100, 1100, 910, 650, 850 };
//                 0    1     2     3    4    5      6    7
int set_max[] = { 1700, 2200, 2100, 2000, 2300, 2100, 1700, 1700 };
//                 0     1      2     3     4    5      6     7
int set_min_Analog[] = { 800, 1000 };
int set_max_Analog[] = { 3800, 3800 };

int ref[] = { 0, 1525, 0, 0, 0, 0, 1175, 0 };
///////////////////////////////////////////////////////////////////

ADS7828 ADD_0;
long Position, last_position = 0;
unsigned long lastTimeFound = 0, lastReset = 0;
int checkOutLineForTimer = 0;

int stateTurn = 2;
int error, power_motor, lastError = 0, leftMotorSpeed, rightMotorSpeed;

////////////////////////////
int ms = 45;
float p = 0.02, d = 0.1;
////////////////////////////
void setup() {
  Wire.begin();
  Wire.setClock(400000L);
  if (useRobot == 1) {
    ADD_0.begin(0x49);
  } else if (useRobot == 2) {
    ADD_0.begin(0x48);
  }

  oled.mode(1);
sound(E_5, 100);
  delay(100);
  sound(E_5, 100);
  delay(100);
  sound(E_5, 100);
  delay(100);
  sound(C_5, 100);
  delay(100);
  sound(D_5, 100);
  delay(100);
  sound(E_5, 300);
  while (!sw_OK()) {
    if (SW_A() == 1) {
      oled.clear();
      sound(C_7, 300);
      viewMinMax();
    }
    int e = adjustError();
    int pm = (e * p) + ((e - lastError) * d);
    int ml = constrain(ms + pm, -100, 100);
    int mr = constrain(ms - pm, -100, 100);
    oled.text(0, 0, "E = %d     ", adjustError());
    oled.text(1, 0, "P = %d     ", readline());
    conditionGreen();
    if (ADD_0.read(1) < ref[1] && ADD_0.read(6) < ref[6]) {
      oled.text(2, 0, "C");
    } else {
      oled.text(2, 0, " ");
    }
    if (stateTurn == 0) {
      oled.text(2, 5, "L");
    } else if (stateTurn == 1) {
      oled.text(2, 5, "R");
    } else if (stateTurn == 3) {
      oled.text(2, 5, "U");
    } else {
      oled.text(2, 5, "F");
    }
    oled.text(3, 0, "%d  ", ml);
    oled.text(3, 5, "%d   ", mr);
    viewSensor();
  }
  stateTurn = 2;
  oled.clear();
  oled.show();
  delay(500);
}

void loop() {
  // viewMinMax();
  LineMainPart();
}