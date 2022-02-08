#include <assert.h>
#include <iostream>
#include <string>

#define MIN_TEMP 0
#define MAX_TEMP 45
#define MIN_SOC 20
#define MAX_SOC 80
#define CHARGE_RATE 0.8

using namespace std;

// bool batteryIsOk(float temperature, float soc, float chargeRate) {
//   if(temperature < 0 || temperature > 45) {
//     cout << "Temperature out of range!\n";
//     return false;
//   } else if(soc < 20 || soc > 80) {
//     cout << "State of Charge out of range!\n";
//     return false;
//   } else if(chargeRate > 0.8) {
//     cout << "Charge Rate out of range!\n";
//     return false;
//   }
//   return true;
// }


class Battery
{
    public:
    bool isBatteryOK(float temperature, float soc, float chargeRate);
    private:
    bool checkTemperatureRange(float temperatue, void(*fnprint)(string));
    bool checkStateOfCharegeRange( float soc, void(*fnprint)(string));
    bool checkChargeRateRange(float rate, void(*fnprint)(string));
    static void print(string output);
};

void Battery::print(string output)
{
    cout << output.append(" is OUT OF RANGE !!!") << ::std::endl;
}

bool Battery::isBatteryOK(float temperature, float soc, float chargeRate)
{
    return checkTemperatureRange(temperature, &print) && checkStateOfCharegeRange(soc, &print)
    && checkChargeRateRange(chargeRate, &print);
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

void testBattery(float temperature, float soc, float chargeRate, bool expected)
{
    Battery b;
    assert(b.isBatteryOK(temperature, soc, chargeRate) == expected);
}

int main() {
  testBattery(58, 90, 0.9, false);
//   assert(batteryIsOk(50, 85, 0) == false);
// Battery b;
// bool result = b.isBatteryOK(250, 70, 0.8);
// printf("result - %d", result);
}
