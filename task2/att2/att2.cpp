#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <clocale>

#include "Hotel.h"
#include "FastRobot.h"
#include "CarefulRobot.h"

#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    srand(static_cast<unsigned int>(time(nullptr)));

    Hotel hotel(3, 3);

    std::vector<std::unique_ptr<Robot>> robots;
    robots.push_back(std::make_unique<FastRobot>("R1"));
    robots.push_back(std::make_unique<CarefulRobot>("R2"));

    int totalHours = 72;

    for (int hour = 1; hour <= totalHours; hour++)
    {
        std::cout << "\n====================================\n";
        std::cout << "ЧАС " << hour << "\n";
        std::cout << "====================================\n";

        hotel.tickRooms();

        if (hour % 24 == 0)
        {
            std::cout << "\n--- ЕЖЕДНЕВНАЯ ПРОВЕРКА УБОРКИ ---\n";
            hotel.dailyCleaningCheck();
        }

        int day = (hour - 1) / 24;
        int attempts = 1 + rand() % (2 + day);

        std::cout << "\nПопыток заселения в этот час: " << attempts << "\n";

        for (int i = 0; i < attempts; i++)
        {
            Guest guest = hotel.createRandomGuest();
            hotel.tryCheckIn(guest, hour);
        }

        for (auto& robot : robots)
        {
            if (robot->getStatus() == RobotStatus::Idle)
            {
                Room* dirtyRoom = hotel.getNextDirtyRoom();

                if (dirtyRoom != nullptr)
                {
                    if (robot->shouldGoCharge() || !robot->canStartCleaning())
                    {
                        robot->startCharging();
                    }
                    else
                    {
                        robot->startCleaning(dirtyRoom);
                    }
                }
                else
                {
                    if (robot->shouldGoCharge())
                    {
                        robot->startCharging();
                    }
                }
            }
        }

        for (auto& robot : robots)
        {
            robot->workOneHour();
        }

        hotel.printRooms();

        std::cout << "\nСостояние роботов:\n";
        for (const auto& robot : robots)
        {
            robot->printStatus();
        }
    }

    std::cout << "\n====================================\n";
    std::cout << "ИТОГИ СИМУЛЯЦИИ\n";
    std::cout << "====================================\n";

    hotel.printRejectedGuests();

    return 0;
}