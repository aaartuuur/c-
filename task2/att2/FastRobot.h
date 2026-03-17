#pragma once
#include "Robot.h"

class FastRobot : public Robot
{
public:
    FastRobot(const std::string& name);

    std::string getType() const override;
    int getCleaningHours() const override;
    int getChargingHours() const override;
    double getLowBatteryLimit() const override;
    double getBatteryUsagePerHour() const override;
    double getBatteryWearAfterCharge() const override;
};