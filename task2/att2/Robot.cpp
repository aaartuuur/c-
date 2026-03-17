#include "Robot.h"
#include <iostream>

Robot::Robot(const std::string& name, double maxBattery)
{
    this->name = name;
    this->maxBattery = maxBattery;
    battery = maxBattery;
    status = RobotStatus::Idle;
    hoursLeft = 0;
    currentRoom = nullptr;
    cleanedRoomsCount = 0;
}

Robot::~Robot()
{
}

RobotStatus Robot::getStatus() const
{
    return status;
}

bool Robot::canStartCleaning() const
{
    double need = getCleaningHours() * getBatteryUsagePerHour();
    return battery >= need;
}

bool Robot::shouldGoCharge() const
{
    return battery <= getLowBatteryLimit();
}

void Robot::startCleaning(Room* room)
{
    if (room == nullptr)
        return;

    currentRoom = room;
    currentRoom->startCleaning();
    status = RobotStatus::Cleaning;
    hoursLeft = getCleaningHours();

    std::cout << name << " (" << getType() << ") начал уборку номера "
        << currentRoom->getNumber() << "\n";
}

void Robot::startCharging()
{
    currentRoom = nullptr;
    status = RobotStatus::Charging;
    hoursLeft = getChargingHours();

    std::cout << name << " (" << getType() << ") поехал на зарядку\n";
}

void Robot::workOneHour()
{
    if (status == RobotStatus::Cleaning)
    {
        battery -= getBatteryUsagePerHour();
        if (battery < 0)
            battery = 0;

        hoursLeft--;

        if (hoursLeft <= 0)
        {
            if (currentRoom != nullptr)
            {
                currentRoom->finishCleaning();
            }

            currentRoom = nullptr;
            status = RobotStatus::Idle;
            cleanedRoomsCount++;

            std::cout << name << " закончил уборку\n";
        }
    }
    else if (status == RobotStatus::Charging)
    {
        hoursLeft--;

        if (hoursLeft <= 0)
        {
            maxBattery -= getBatteryWearAfterCharge();
            if (maxBattery < 20)
                maxBattery = 20;

            battery = maxBattery;
            status = RobotStatus::Idle;

            std::cout << name << " зарядился. Новая максимальная ёмкость = "
                << maxBattery << "\n";
        }
    }
}

void Robot::printStatus() const
{
    std::cout << name << " (" << getType() << ") | ";

    if (status == RobotStatus::Idle)
        std::cout << "свободен";
    else if (status == RobotStatus::Cleaning)
        std::cout << "убирает номер " << currentRoom->getNumber();
    else if (status == RobotStatus::Charging)
        std::cout << "заряжается";

    std::cout << " | батарея: " << battery
        << "/" << maxBattery
        << " | убрано номеров: " << cleanedRoomsCount
        << "\n";
}