#pragma once

#include <iostream>
#include <unordered_map>
using namespace std;

class Airplane {
private:
    unordered_map<string, bool> _seats;
    string _flightNumber;
    string _date;
public:
    string getDate();
    string getFlightNumber();
    Airplane(const string &flightNumber, const string& date, int numberOfRows); // todo: add prices to seats somehow
    bool book(const string& seatNumber); // todo: change return type to ticket later
    bool refund(const string& seatNumber);
    bool check(const string& seatNumber);
};
