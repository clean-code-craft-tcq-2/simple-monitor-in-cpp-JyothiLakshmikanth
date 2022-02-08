#include <assert.h>
#include <iostream>
#include "BatteryCheck.h"

class TestBattery
{
  public:
  void testBattery(float temperature, float soc, float chargeRate, bool expected);
};

void TestBattery::testBattery(float temperature, float soc, float chargeRate, bool expected)
{
    Battery battery;
    assert(battery.isBatteryOK(temperature, soc, chargeRate) == expected);
}
