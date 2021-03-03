#include <assert.h>
#include "BMS_Types.h"

static int batteryIsOk(float temperature, float soc, float chargeRate)
{

  if((!CheckTemperatureInRange(temperature,(float)TEMPERATURE_UL,(float)TEMPERATURE_LL)) ||
     (!CheckSocInRange(soc,(float)SOC_UL,(float)SOC_LL)) ||
     (!CheckChargeRateInRange(chargeRate,(float)CHARGERATE_UL)))
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
