#include "../include/Ticket.h"

Ticket::Ticket(const string& username, const string& id, int price, const string& date, bool status, const string& flightNumber, const string& seatNumber)
        : username(username), id(id), price(price), date(date), status(status), flightNumber(flightNumber), seatNumber(seatNumber) {}

string Ticket::getUsername() const {
    return username;
}

string Ticket::getId() const {
    return id;
}

int Ticket::getPrice() const {
    return price;
}

string Ticket::getDate() const {
    return date;
}

bool Ticket::getStatus() const {
    return status;
}

string Ticket::getFlightNumber() const {
    return flightNumber;
}

string Ticket::getSeatNumber() const {
    return seatNumber;
}

void Ticket::setUsername(const string& newUsername) {
    username = newUsername;
}

void Ticket::setId(const string& newId) {
    id = newId;
}

void Ticket::setPrice(int newPrice) {
    price = newPrice;
}

void Ticket::setDate(const string& newDate) {
    date = newDate;
}

void Ticket::setStatus(bool newStatus) {
    status = newStatus;
}

void Ticket::setFlightNumber(const string& newFlightNumber) {
    flightNumber = newFlightNumber;
}

void Ticket::setSeatNumber(const string& newSeatNumber) {
    seatNumber = newSeatNumber;
}

void Ticket::reset() {
    username = "";
    id = "";
    status = false;
}