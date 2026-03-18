#include "Hotel.h"
#include <iostream>
#include <cstdlib>

Hotel::Hotel(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    nextGuestId = 1;

    rooms.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            rooms[i].push_back(Room(i + 1, j + 1));
        }
    }
}

Guest Hotel::createRandomGuest()
{
    int stay = 3 + rand() % 10;
    return Guest(nextGuestId++, stay);
}

bool Hotel::tryCheckIn(const Guest& guest, int currentHour)
{
    for (auto& row : rooms)
    {
        for (auto& room : row)
        {
            if (room.isCleanFree())
            {
                room.checkIn(guest);
                return true;
            }
        }
    }

    std::cout << "Нет свободных чистых номеров для гостя #"
        << guest.getId() << "\n";

    rejectedGuests.push_back(RejectedGuest(currentHour, guest));
    return false;
}

void Hotel::tickRooms()
{
    for (auto& row : rooms)
    {
        for (auto& room : row)
        {
            room.tickHour();
        }
    }
}

void Hotel::dailyCleaningCheck()
{
    for (auto& row : rooms)
    {
        for (auto& room : row)
        {
            room.markForDailyCleaning();
        }
    }
}

Room* Hotel::getNextDirtyRoom()
{
    for (auto& row : rooms)
    {
        for (auto& room : row)
        {
            if (room.needsCleaning())
            {
                return &room;
            }
        }
    }
    return nullptr;
}

void Hotel::printRooms() const
{
    std::cout << "\nСостояние номеров:\n";
    for (const auto& row : rooms)
    {
        for (const auto& room : row)
        {
            room.printShort();
            std::cout << "  ";
        }
        std::cout << "\n";
    }
}

void Hotel::printRejectedGuests() const
{
    std::cout << "\nКлиенты, которые не смогли заселиться:\n";

    if (rejectedGuests.empty())
    {
        std::cout << "Таких клиентов нет\n";
        return;
    }

    for (const auto& g : rejectedGuests)
    {
        g.print();
    }
}