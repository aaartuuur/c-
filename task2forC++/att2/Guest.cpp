#include "Guest.h"

Guest::Guest(int id, int stayHours)
{
    this->id = id;
    this->stayHours = stayHours;
}

int Guest::getId() const
{
    return id;
}

int Guest::getStayHours() const
{
    return stayHours;
}