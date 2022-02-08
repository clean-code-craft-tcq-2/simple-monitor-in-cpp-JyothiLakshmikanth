#include "BatteryCheck.h"
#include <iostream>
#include <string>

using namespace std;

void Battery::printWarning(string output)
{
    cout << output.append(" is OUT OF RANGE !!!") << ::std::endl;
}

bool Battery::isBatteryOK(float temperature, float soc, float chargeRate)
{
    bool isOK = false;
    if(checkTemperatureRange(temperature, &printWarning) && checkStateOfCharegeRange(soc, &printWarning) && checkChargeRateRange(chargeRate, &printWarning))
    {
        isOK = true;
        cout << "ALL IS WELL !!!!" << ::std::endl;
    }
    return isOK;
}

bool Battery::checkTemperatureRange(float temperatue, void(*fnprint)(string))
{
    if(temperatue > MIN_TEMP && temperatue < MAX_TEMP)
    {
        return true;
    }
    fnprint("TEMPERATURE");
    return false;
}

bool Battery::checkStateOfCharegeRange(float soc, void(*fnprint)(string))
{
    if(soc > MIN_SOC && soc < MAX_SOC)
    {
        return true;
    }
    fnprint("SOC");
    return false;
}

bool Battery::checkChargeRateRange(float rate, void(*fnprint)(string))
{
    if(rate < CHARGE_RATE)
    {
        return true;
    }
    fnprint("CHARGE RATE");
    return false;
}
