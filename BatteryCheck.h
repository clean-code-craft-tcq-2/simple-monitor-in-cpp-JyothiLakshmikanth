#include <iostream>
#include <string>

using namespace std;

#define MIN_TEMP 0
#define MAX_TEMP 45
#define MIN_SOC 20
#define MAX_SOC 80
#define CHARGE_RATE 0.8

class Battery
{
    public:
    bool isBatteryOK(float temperature, float soc, float chargeRate);

    private:
    bool checkTemperatureRange(float temperatue, void(*fnprint)(string));
    bool checkStateOfCharegeRange( float soc, void(*fnprint)(string));
    bool checkChargeRateRange(float rate, void(*fnprint)(string));
    static void printWarning(string output);
};
