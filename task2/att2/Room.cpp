#include "Room.h"
#include <iostream>

Room::Room(int row, int col)
{
    this->row = row;
    this->col = col;
    status = RoomStatus::CleanFree;
    hasGuest = false;
    remainingStayHours = 0;
    hoursSinceLastCleaning = 0;
}

std::string Room::getNumber() const
{
    return std::to_string(row) + "-" + std::to_string(col);
}

RoomStatus Room::getStatus() const
{
    return status;
}

bool Room::isCleanFree() const
{
    return status == RoomStatus::CleanFree;
}

bool Room::needsCleaning() const
{
    return status == RoomStatus::NeedsCleaning;
}

void Room::checkIn(const Guest& guest)
{
    currentGuest = guest;
    hasGuest = true;
    remainingStayHours = guest.getStayHours();
    status = RoomStatus::Occupied;

    std::cout << "Гость #" << guest.getId()
        << " заселился в номер " << getNumber()
        << " на " << guest.getStayHours() << " ч.\n";
}

void Room::tickHour()
{
    if (status == RoomStatus::Occupied)
    {
        remainingStayHours--;

        if (remainingStayHours <= 0)
        {
            std::cout << "Гость #" << currentGuest.getId()
                << " выехал из номера " << getNumber() << "\n";

            hasGuest = false;
            status = RoomStatus::NeedsCleaning;
        }
    }

    if (status != RoomStatus::Cleaning)
    {
        hoursSinceLastCleaning++;
    }
}

void Room::markForDailyCleaning()
{
    if (status == RoomStatus::CleanFree && hoursSinceLastCleaning >= 24)
    {
        status = RoomStatus::NeedsCleaning;
        std::cout << "Номер " << getNumber()
            << " отправлен на ежедневную уборку\n";
    }
}

void Room::startCleaning()
{
    status = RoomStatus::Cleaning;
}

void Room::finishCleaning()
{
    status = RoomStatus::CleanFree;
    hoursSinceLastCleaning = 0;

    std::cout << "Номер " << getNumber() << " убран\n";
}

void Room::printShort() const
{
    std::cout << "[" << getNumber() << ": ";

    if (status == RoomStatus::CleanFree)
        std::cout << "чистый";
    else if (status == RoomStatus::Occupied)
        std::cout << "занят";
    else if (status == RoomStatus::NeedsCleaning)
        std::cout << "грязный";
    else if (status == RoomStatus::Cleaning)
        std::cout << "уборка";

    std::cout << "]";
}