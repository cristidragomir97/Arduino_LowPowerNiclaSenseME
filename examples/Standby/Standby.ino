
#include <LowPowerNicla.h>

LowPowerNicla lowPowerNicla;

void setup(){

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    lowPowerNicla.begin();
    lowPowerNicla.setWakeUpPin(GPIO0);
    lowPowerNicla.disableBHY2Sensors();
    lowPowerNicla.standby();
}

void loop(){
    // put your main code here, to run repeatedly:
}
