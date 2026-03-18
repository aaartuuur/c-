#include "CarefulRobot.h"

CarefulRobot::CarefulRobot(const std::string& name)
    : Robot(name, 120)
{
}

std::string CarefulRobot::getType() const
{
    return "Аккуратный";
}

int CarefulRobot::getCleaningHours() const
{
    return 2;
}

int CarefulRobot::getChargingHours() const
{
    return 3;
}

double CarefulRobot::getLowBatteryLimit() const
{
    return 30;
}

double CarefulRobot::getBatteryUsagePerHour() const
{
    return 10;
}

double CarefulRobot::getBatteryWearAfterCharge() const
{
    return 1.0;
}