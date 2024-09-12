#include <iostream>
#include <unordered_map>
#include "ConfigFileParser.h"
#include "UserInputParser.h"
#include "CommandParams.h"
using namespace std;

int main() {
    vector<Airplane*>* airplanes = ConfigFileParser::parseFile(R"(E:\KSE\year-2\oop\booking\config.txt)");
    unordered_map<string, Ticket*> bookedTickets;

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

            for (auto airplane : *airplanes) {
                if ((airplane->getFlightNumber()) != flightNumber || (airplane->getDate() != date)) continue;
                Ticket* ticket = airplane->book(seatNumber, username);

                if (ticket == nullptr) {
                    cout << "Booking failed. You either chose taken seat or such a seat does not exist" << endl;
                    break;
                }

                bookedTickets[ticket->getId()] = ticket;

                cout << ">Confirmed with ID " << ticket->getId() << endl;
            }
        } else {
            cout << "No such command. Try again" << endl;
        }

        cout << "<";
        getline(cin, userInput);
    }

    return 0;
}