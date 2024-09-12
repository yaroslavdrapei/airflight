#pragma once

#include <iostream>
#include <unordered_map>
#include "Ticket.h"
using namespace std;

class Airplane {
private:
    unordered_map<string, Ticket*> seats;
    string flightNumber;
    string date;
public:
    string getDate() const;
    string getFlightNumber() const;
    Airplane(const string &flightNumber, const string& date, int numberOfRows); // todo: add prices to seats somehow
    Ticket* book(const string& seatNumber, const string& username); // todo: change return type to ticket later
    bool refund(const string& id);
    bool check(const string& seatNumber);
};
