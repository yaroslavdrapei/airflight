#include <iostream>
#include <unordered_map>
#include "ConfigFileParser.h"
#include "UserInputParser.h"
#include "CommandParams.h"
#include "AirplanesManager.h"
#include "TicketsManager.h"
#include "Airplane.h"
#include "BookingCli.h"

using namespace std;

int main() {
    AirplanesManager airplanesManager = AirplanesManager(ConfigFileParser::parseFile(R"(E:\KSE\year-2\oop\booking\config.txt)"));
    TicketsManager bookedTicketsManager = TicketsManager();

    string userInput;
    cout << "<";
    getline(cin, userInput);

    BookingCli bookingCli = BookingCli(airplanesManager, bookedTicketsManager);

    while (userInput != "quit") {
        CommandParams parsedInput = UserInputParser::parse(userInput);
        bookingCli.setParams(parsedInput);

        string command = parsedInput.command;

        if (command == "book") bookingCli.bookCommand();
        else if (command == "return") bookingCli.returnCommand();
        else if (command == "check") bookingCli.checkCommand();
        else if (command == "view") bookingCli.viewCommand();
        else cout << "No such command. Try again" << endl;

        cout << "<";
        getline(cin, userInput);
    }

    return 0;
}

// todo: improve memory management
// todo: implement normal id generation