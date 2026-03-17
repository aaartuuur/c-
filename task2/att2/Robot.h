#pragma once
#include <string>
#include "Room.h"

enum class RobotStatus
{
    Idle,
    Cleaning,
    Charging
};

class Robot
{
protected:
    std::string name;
    RobotStatus status;
    double battery;
    double maxBattery;
    int hoursLeft;
    Room* currentRoom;
    int cleanedRoomsCount;

public:
    Robot(const std::string& name, double maxBattery);
    virtual ~Robot();

    virtual std::string getType() const = 0;
    virtual int getCleaningHours() const = 0;
    virtual int getChargingHours() const = 0;
    virtual double getLowBatteryLimit() const = 0;
    virtual double getBatteryUsagePerHour() const = 0;
    virtual double getBatteryWearAfterCharge() const = 0;

    RobotStatus getStatus() const;

    bool canStartCleaning() const;
    bool shouldGoCharge() const;

    void startCleaning(Room* room);
    void startCharging();
    void workOneHour();

    void printStatus() const;
};