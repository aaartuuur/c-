#include "RejectedGuest.h"
#include <iostream>

RejectedGuest::RejectedGuest(int hour, const Guest& guest)
{
    this->hour = hour;
    this->guest = guest;
}

void RejectedGuest::print() const
{
    std::cout << "Час " << hour
        << ": гость #" << guest.getId()
        << " не смог заселиться\n";
}