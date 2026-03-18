#pragma once

class Guest
{
private:
    int id;
    int stayHours;

public:
    Guest(int id = 0, int stayHours = 0);

    int getId() const;
    int getStayHours() const;
};