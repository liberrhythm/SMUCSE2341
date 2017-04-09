#ifndef AIRPORT_H
#define AIRPORT_H

#include "DSString.h"
#include "DSVector.h"
#include <iostream>

class Airport {
    public:
        Airport();
        Airport(String);
        Airport(String, double, int);
        bool operator==(const Airport&);
        String getName();
        void setName(String);
        double getCost();
        void setCost(double);
        int getTime();
        void setTime(int);

        void print();

    private:
        String name;
        double cost;
        int time;
};

#endif // AIRPORT_H
