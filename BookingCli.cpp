#include "BookingCli.h"

void BookingCli::viewById(const string &id) {
    Ticket* ticket = bookedTicketsManager.findById(id);

    if (ticket != nullptr) {
        cout << "Flight " << ticket->getFlightNumber() << ", " << ticket->getDate() << ", ";
        cout << "seat " << ticket->getSeatNumber() << ", " << "price " << ticket->getPrice();
        cout << "$, " << ticket->getUsername() << endl;
    } else {
        cout << "No ticket with this ID" << endl;
    }
}

void BookingCli::viewByUsername(const string &username) {
    int index = 1;

    vector<Ticket*> bookedTickets = bookedTicketsManager.findByUsername(username);

    for (auto ticket : bookedTickets) {
        cout << index << ". " << "Flight " << ticket->getFlightNumber() << ", ";
        cout << ticket->getDate() << ", " << "seat " << ticket->getSeatNumber() << ", ";
        cout << "price " << ticket->getPrice() << "$" << endl;
        index++;
    }
}

void BookingCli::viewByDateAndFlight(const string &date, const string &flightNumber) {
    Airplane* airplane = airplanesManager.findAirplaneByDateAndFlightNumber(date, flightNumber);

    vector<Ticket*> tickets = airplane->getTicketsByStatus(true);

    for (auto& ticket : tickets) {
        cout << ticket->getSeatNumber() << " " << ticket->getUsername() << " " << ticket->getPrice() << "$";
        if (ticket != tickets.back()) {
            cout << ", ";
        }
    }

    cout << endl;
}

BookingCli::BookingCli(AirplanesManager airplanesManager, TicketsManager bookedTicketsManager) : airplanesManager(airplanesManager), bookedTicketsManager(bookedTicketsManager) {}

vector<string> BookingCli::getParams() {
    return params;
}

void BookingCli::setParams(CommandParams newParams) {
    params = newParams.params;
}

void BookingCli::checkCommand() {
    string date = params[0];
    string flightNumber = params[1];

    Airplane* airplane = airplanesManager.findAirplaneByDateAndFlightNumber(date, flightNumber);

    vector<Ticket*> availableTickets = airplane->getTicketsByStatus(false);

    if (availableTickets.empty()) {
        cout << "No tickets available" << endl;
        return;
    }

    for (auto ticket : availableTickets) {
        cout << ticket->getSeatNumber() << " " << ticket->getPrice() << "$";
        if (ticket != availableTickets.back()) {
            cout << ", ";
        }
    }

    cout << endl;
}

void BookingCli::bookCommand() {
    string date = params[0];
    string flightNumber = params[1];
    string seatNumber = params[2];
    string username = params[3];

    Airplane* airplane = airplanesManager.findAirplaneByDateAndFlightNumber(date, flightNumber);

    Ticket *ticket = airplane->book(seatNumber, username);

    if (ticket == nullptr) {
        cout << "Booking failed. You either chose taken seat or such a seat does not exist" << endl;
        return;
    }

    bookedTicketsManager.add(ticket);

    cout << ">Confirmed with ID " << ticket->getId() << endl;
}

void BookingCli::returnCommand() {
    string id = params[0];

    Ticket* ticket = bookedTicketsManager.findById(id);

    if (ticket == nullptr) {
        cout << "You cannot return the ticket that is not booked or does not exist" << endl;
        return;
    }

    int price = ticket->getPrice();
    string username = ticket->getUsername();

    ticket->reset();

    bookedTicketsManager.remove(id);

    cout << ">Confirmed " << price << "$ refund for " << username << endl;
}

void BookingCli::viewCommand() {
    string option = params[0];

    if (option == "username") {
        string username = params[1];
        viewByUsername(username);
    }

    else if (option == "flight") {
        string date = params[1];
        string flightNumber = params[2];
        viewByDateAndFlight(date, flightNumber);
    }
    else { //by id
        viewById(option);
    }
}
