#include "FastRobot.h"

FastRobot::FastRobot(const std::string& name)
    : Robot(name, 100)
{
}

std::string FastRobot::getType() const
{
    return "Быстрый";
}

int FastRobot::getCleaningHours() const
{
    return 1;
}

int FastRobot::getChargingHours() const
{
    return 2;
}

double FastRobot::getLowBatteryLimit() const
{
    return 20;
}

double FastRobot::getBatteryUsagePerHour() const
{
    return 18;
}

double FastRobot::getBatteryWearAfterCharge() const
{
    return 2.5;
}