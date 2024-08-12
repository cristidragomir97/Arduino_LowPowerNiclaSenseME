#include <Arduino.h>
#include "Arduino_BHY2.h"
#include "Nicla_System.h"

#include "app_error_weak.h"
#include "app_util.h"
#include "nordic_common.h"
#include "nrf_error.h"
#include "nrf_gpio.h"
#include "sdk_errors.h"
#include "app_error.h" 
#include <nrf_soc.h>

class LowPowerNicla {
    public: 
        LowPowerNicla();
        void begin();
        void standby();
        void setWakeUpPin(uint8_t pin);
        void disableBHY2Sensors();


        friend class BQ25120A;
};