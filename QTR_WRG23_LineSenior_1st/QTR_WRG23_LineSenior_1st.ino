#include <POP32.h>
#include <ADS7828.h>

ADS7828 ADD_0;

void setup() {
  Wire.begin();
  Wire.setClock(400000L);
  ADD_0.begin(0x49);
  oled.mode(1);

  while (!sw_OK()) {
    viewPID();
  }
  oled.clear();
  delay(500);
}

int stateTurn;
int ref[] = { 1000, 1000 };
void loop() {
  if (ADD_0.read(0) < ref[0] && ADD_0.read(7) < ref[1]) {
    delay(50);
    conditionGreen();
    if (stateTurn == 0) {
      L();
    } else if (stateTurn == 1) {
      R();
    } else if (stateTurn == 3) {
      U();
    }
    AO();
    beep();
    viewStateTurn();
    waitSW_OK_bmp();
    delay(500);
  } else {
    pid(55, 0.03, 0.1);
  }
}