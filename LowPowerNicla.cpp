#include "LowPowerNicla.h"

LowPowerNicla::LowPowerNicla(){
}

void LowPowerNicla::begin(){
    // enable regulators when waking up from standby
    NRF_POWER->DCDCEN = 1;
    nicla::enable3V3LDO();
    nicla::begin();
}

void LowPowerNicla::standby(){
    NRF_POWER->DCDCEN = 0;
    nicla::disableLDO();
    BQ25120A bq = BQ25120A();
    bq.setHighImpedanceModeEnabled(true);
    NRF_POWER->SYSTEMOFF = 1;
}
        
void LowPowerNicla::setWakeUpPin(uint8_t pin){
    pinMode(pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(pin), []{}, RISING);
    NRF_GPIO->PIN_CNF[pin] &= ~((uint32_t)GPIO_PIN_CNF_SENSE_Msk);
    NRF_GPIO->PIN_CNF[pin] |= ((uint32_t)GPIO_PIN_CNF_SENSE_High << GPIO_PIN_CNF_SENSE_Pos);
}

void LowPowerNicla::disableBHY2Sensors(){
    BHY2.begin();
      for (int id = 0; id < 255; id++) {
        if (BHY2.hasSensor(id)){
            BHY2.configureSensor(id, 0, 1);
        }
    }
}