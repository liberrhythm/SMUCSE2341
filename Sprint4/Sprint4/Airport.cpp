#include "Airport.h"

Airport::Airport() {
    setName("");
    setCost(0);
    setTime(0);
}

Airport::Airport(String name) {
    setName(name);
    setCost(0);
    setTime(0);
}

Airport::Airport(String name, double cost, int time) {
    setName(name);
    setCost(cost);
    setTime(time);
}

bool Airport::operator==(const Airport& a) {
    if (name == a.name) {
        return true;
    }
    return false;
}

String Airport::getName() {
    return name;
}

void Airport::setName(String n) {
    name = n;
}

double Airport::getCost() {
    return cost;
}

void Airport::setCost(double c) {
    cost = c;
}

int Airport::getTime() {
    return time;
}

void Airport::setTime(int t) {
    time = t;
}

void Airport::print() {
    std::cout << name << " " << cost << " " << time << std::endl;
}
