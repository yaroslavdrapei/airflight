#include "Airplane.h"

using namespace std;

Airplane::Airplane(const string &date, const string &flightNumber, int numberOfColumns,
                   vector<RowPricing> rowPrices) : date(date), flightNumber(flightNumber),
                                                   rowPrices(rowPrices) {

    // here i'm filling in seats with not booked tickets
    int numberOfRows = rowPrices.back().end;

    for (int row = 0; row < numberOfRows; row++) {
        for (int col = 0; col < numberOfColumns; col++) {
            string seatNumber = generateSeatNumber(row, col);
            int price = calcPrice(seatNumber);

            seats[seatNumber] = new Ticket("", "", price, date, false, flightNumber);
        }
    }
}

string Airplane::getDate() const {
    return date;
}

string Airplane::getFlightNumber() const {
    return flightNumber;
};

void Airplane::setDate(const string &newDate) {
    date = newDate;
}

void Airplane::setFlightNumber(const string &newFlightNumber) {
    flightNumber = newFlightNumber;
}

bool Airplane::check(const string &seatNumber) {
    if (seats.find(seatNumber) == seats.end()) {
        return false;
    }

    if (seats[seatNumber]->getStatus()) {
        return false;
    }

    return true;
}

int Airplane::refund(const string &id) {
    for (auto &seat: seats) {
        Ticket* ticket = seat.second;

        if (ticket->getId() != id) continue;

        ticket->reset();

        return ticket->getPrice();
    }

    cout << "Ticket was not booked!" << endl;
    return 0;
}

Ticket *Airplane::book(const string &seatNumber, const string &username) {
    string id = seatNumber + flightNumber + date;

    if (!check(seatNumber)) return nullptr;

    Ticket *ticket = seats[seatNumber];

    ticket->setStatus(true);
    ticket->setUsername(username);
    ticket->setId(id);

    return ticket;
}

int Airplane::calcPrice(const string &seatNumber) {
//    int row = seatNumber[0]  - '0';
    string rowString;

    for (auto chr : seatNumber) {
        if (!isdigit(chr)) break;
        rowString += chr;
    }

    int row = stoi(rowString);

    for (auto &rowPrice: rowPrices) {
        if ((rowPrice.start <= row) && (row <= rowPrice.end)) {
            return rowPrice.price;
        }
    }

    cout << "Row not found! Means seat is free!" << endl;
    return 0;
}

string Airplane::generateSeatNumber(int row, int col) {
    int code = 65 + col;
    return to_string(row+1) + string{(char)code};
}