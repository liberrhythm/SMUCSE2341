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

Airport::Airport(String name, int cost, int time) {
    setName(name);
    setCost(cost);
    setTime(time);
}

String Airport::getName() {
    return name;
}

void Airport::setName(String n) {
    name = n;
}

int Airport::getCost() {
    return cost;
}

void Airport::setCost(int c) {
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
