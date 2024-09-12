#include "Airplane.h"
#include "InputParser.h"
#include "Ticket.h"
using namespace std;

Airplane::Airplane(const string &data) {
    InputParser inputParser(data);

    date = inputParser.date;
    flightNumber = inputParser.flightNumber;
    numberOfRows = inputParser.numberOfRows;
    prices = inputParser.prices;
    numberOfCols = inputParser.numberOfCols;

    for (int row = 0; row < numberOfRows; row++) {
        seats.push_back(vector<Ticket*>(0));
        for (int col = 0; col < numberOfCols; col++) {
            int code = 65 + col;
            string seatNumber = to_string(row+1) + string{(char)code};

            int price = 0;

            for (auto details : prices) {
                if ((details.start <= row) && (details.end >= row)) {
                    price = details.price;
                    break;
                }
            }

            seats[row].push_back(new Ticket(seatNumber, price));
        }
    }
}

void Airplane::book(const string& seatNumber, const string& passengerName) {
    auto seat = seats.find(seatNumber);

    if (seat == seats.end()) {
        return;
    }

    Ticket* ticket = seat->second;

    if (!ticket->getIsBooked()) {
        ticket->book(passengerName);
    } else {

    }
}