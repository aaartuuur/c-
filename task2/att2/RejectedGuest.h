#pragma once
#include "Guest.h"

class RejectedGuest
{
private:
    int hour;
    Guest guest;

public:
    RejectedGuest(int hour, const Guest& guest);

    void print() const;
};