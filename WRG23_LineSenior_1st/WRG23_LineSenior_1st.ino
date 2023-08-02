#include <POP32.h>
#include <ADS7828.h>

ADS7828 ADD_0;

int set_min[] = { 648, 317, 752, 844, 575, 947, 537, 499 };
int set_max[] = { 2477, 1232, 1781, 2387, 2008, 2857, 1641, 1994 };

int set_min_Analog[] = { 1278, 763 };
int set_max_Analog[] = { 3877, 3860 };

int ref[] = {
  900,
  800,
  1400,
  1850,
  1450,
  1950,
  1250,
  1000,
};


long Position, last_position = 0;
unsigned long lastTimeFound = 0, lastReset = 0;
int checkOutLineForTimer = 0;

int stateTurn = 2;
int error, power_motor, lastError = 0, leftMotorSpeed, rightMotorSpeed;

void setup() {
  Wire.begin();
  Wire.setClock(400000L);
  ADD_0.begin(0x49);

  oled.mode(1);

  while (!sw_OK()) {
    oled.text(0, 0, "E = %d     ", adjustError());
    oled.text(1, 0, "P = %d     ", readline());
    viewSensor();
  }
  oled.clear();
  oled.show();
  delay(500);
}

void loop() {
  // viewSensor();
  LineMainPart();
  // TestconditionGreen();
}