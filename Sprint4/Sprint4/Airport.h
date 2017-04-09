#ifndef AIRPORT_H
#define AIRPORT_H

#include "DSString.h"
#include "DSVector.h"
#include <iostream>

class Airport {
    public:
        Airport();
        Airport(String);
        Airport(String, int, int);
        bool operator==(const Airport&);
        String getName();
        void setName(String);
        int getCost();
        void setCost(int);
        int getTime();
        void setTime(int);

        void print();

    private:
        String name;
        int cost;
        int time;
};

#endif // AIRPORT_H
