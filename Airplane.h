#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include "Ticket.h"
#include "RowPricing.h"
using namespace std;

class Airplane {
private:
    unordered_map<string, Ticket*> seats;
    string flightNumber;
    string date;
    vector<RowPricing> rowPrices;
public:
    Airplane(const string& date, const string &flightNumber, int numberOfColumns, vector<RowPricing> rowPrices);

    string getDate() const;
    string getFlightNumber() const;

    void setDate(const string& newDate);
    void setFlightNumber(const string& newFlightNumber);

    Ticket* book(const string& seatNumber, const string& username);
    int refund(const string& id);
    bool check(const string& seatNumber);
    int calcPrice(const string& seatNumber);
    string generateSeatNumber(int row, int col);
    vector<Ticket*> getTicketsByStatus(bool status);
};
