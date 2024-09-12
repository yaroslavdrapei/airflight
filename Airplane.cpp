#include <iostream>
#include "Airplane.h"

using namespace std;

Airplane::Airplane(const string& flightNumber, const string& date, int numberOfRows)  : _date(date), _flightNumber(flightNumber) {}

string Airplane::getDate() { return _date; }

string Airplane::getFlightNumber() { return _flightNumber; };

bool Airplane::check(const string& seatNumber) {
    if (_seats.find(seatNumber) == _seats.end()) {
        return false;
    }

    if (_seats[seatNumber]) {
        return false;
    }

    return true;
}

bool Airplane::refund(const string& seatNumber) {}

bool Airplane::book(const string& seatNumber) {}

