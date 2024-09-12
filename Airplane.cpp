#include <iostream>
#include "Airplane.h"

using namespace std;

Airplane::Airplane(const string& flightNumber, const string& date, int numberOfRows)  : date(date), flightNumber(flightNumber) {}

string Airplane::getDate() const {
    return date;
}

string Airplane::getFlightNumber() const {
    return flightNumber;
};

bool Airplane::check(const string& seatNumber) {
    if (seats.find(seatNumber) == seats.end()) {
        return false;
    }

    if (seats[seatNumber]) {
        return false;
    }

    return true;
}

bool Airplane::refund(const string& seatNumber) {}

Ticket* Airplane::book(const string& seatNumber) {}

