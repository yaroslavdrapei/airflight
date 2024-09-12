#pragma once
#include <iostream>
using namespace std;

class Ticket {
private:
    string username;
    string id;
    int price;
    string date;
    bool status;
    string flightNumber;
public:
    string getUsername() const;
    string getId() const;
    int getPrice() const;
    string getDate() const;
    bool getStatus() const;
    string getFlightNumber() const;

    void setUsername(const string& newUsername);
    void setId(const string& newId);
    void setPrice(int newPrice);
    void setDate(const string& newDate);
    void setStatus(bool newStatus);
    void setFlightNumber(const string& newFlightNumber);
};
