#pragma once
#include <string>
#include "Guest.h"

enum class RoomStatus
{
    CleanFree,
    Occupied,
    NeedsCleaning,
    Cleaning
};

class Room
{
private:
    int row;
    int col;
    RoomStatus status;

    Guest currentGuest;
    bool hasGuest;
    int remainingStayHours;
    int hoursSinceLastCleaning;

public:
    Room(int row = 0, int col = 0);

    std::string getNumber() const;
    RoomStatus getStatus() const;

    bool isCleanFree() const;
    bool needsCleaning() const;

    void checkIn(const Guest& guest);
    void tickHour();
    void markForDailyCleaning();

    void startCleaning();
    void finishCleaning();

    void printShort() const;
};