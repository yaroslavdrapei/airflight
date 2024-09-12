#include <iostream>
#include <unordered_map>
#include "ConfigFileParser.h"
#include "UserInputParser.h"
#include "CommandParams.h"

using namespace std;

int main() {
    vector<Airplane *> *airplanes = ConfigFileParser::parseFile(R"(E:\KSE\year-2\oop\booking\config.txt)");
    unordered_map<string, Ticket *> bookedTickets;

    string userInput;
    cout << "<";
    getline(cin, userInput);

    while (userInput != "quit") {
        CommandParams parsedInput = UserInputParser::parse(userInput);
        string command = parsedInput.command;

        if (command == "book") {
            string date = parsedInput.params[0];
            string flightNumber = parsedInput.params[1];
            string seatNumber = parsedInput.params[2];
            string username = parsedInput.params[3];

            for (auto airplane: *airplanes) {
                if ((airplane->getFlightNumber()) != flightNumber || (airplane->getDate() != date)) continue;
                Ticket *ticket = airplane->book(seatNumber, username);

                if (ticket == nullptr) {
                    cout << "Booking failed. You either chose taken seat or such a seat does not exist" << endl;
                    break;
                }

                bookedTickets[ticket->getId()] = ticket;

                cout << ">Confirmed with ID " << ticket->getId() << endl;
            }
        }
        else if (command == "return") {
            string id = parsedInput.params[0];

            if (bookedTickets.find(id) != bookedTickets.end()) {
                Ticket* ticket = bookedTickets[id];

                int price = ticket->getPrice();
                string username = ticket->getUsername();

                ticket->reset();

                bookedTickets.erase(id);

                cout << ">Confirmed " << price << "$ refund for " << username << endl;
            }
            else {
                cout << "You cannot return the ticket that is not booked or does not exist" << endl;
            }
        }
        else if (command == "check") {
            string date = parsedInput.params[0];
            string flightNumber = parsedInput.params[1];

            for (auto airplane: *airplanes) {
                if ((airplane->getFlightNumber()) != flightNumber || (airplane->getDate() != date)) continue;

                vector<Ticket*> availableTickets = airplane->getAvailableTickets();

                if (availableTickets.empty()) {
                    cout << "No tickets available" << endl;
                    break;
                }

                for (auto ticket : availableTickets) {
                    cout << ticket->getSeatNumber() << " " << ticket->getPrice() << "$";
                    if (ticket != availableTickets.back()) {
                        cout << ", ";
                    }
                }

                cout << endl;
                break;
            }
        }
        else {
            cout << "No such command. Try again" << endl;
        }

        cout << "<";
        getline(cin, userInput);
    }

    return 0;
}