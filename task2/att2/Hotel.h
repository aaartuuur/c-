#pragma once
#include <vector>
#include "Room.h"
#include "RejectedGuest.h"

class Hotel
{
private:
    int rows;
    int cols;
    std::vector<std::vector<Room>> rooms;
    std::vector<RejectedGuest> rejectedGuests;
    int nextGuestId;

public:
    Hotel(int rows, int cols);

    Guest createRandomGuest();
    bool tryCheckIn(const Guest& guest, int currentHour);

    void tickRooms();
    void dailyCleaningCheck();

    Room* getNextDirtyRoom();

    void printRooms() const;
    void printRejectedGuests() const;
};