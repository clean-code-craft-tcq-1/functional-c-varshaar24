#include <assert.h>
#include <stdbool.h>
#include "BMS_Types.h"


static int batteryIsOk(float temperature, float soc, float chargeRate)
{

    bool Temp_b;
    bool Soc_b;
    bool Rate_b;


    Temp_b = !CheckTemperatureInRange(temperature,(float)TEMPERATURE_UL,(float)TEMPERATURE_LL);
    Soc_b= !CheckSocInRange(soc,(float)SOC_UL,(float)SOC_LL);
    Rate_b = !CheckChargeRateInRange(chargeRate,(float)CHARGERATE_UL)
            ;
  if((Temp_b) ||
     (Soc_b) ||
     (Rate_b))
  {
    return 0;
  }
  return 1;
}

int main()
{
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(-1, 80, 0));
    assert(!batteryIsOk(50, 85, 0));
    assert(!batteryIsOk(25, 15, 0));
    assert(!batteryIsOk(40, 85, 0));
    assert(!batteryIsOk(40, 80, 0.9));
  return 0;
}
