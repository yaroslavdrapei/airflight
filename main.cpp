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
    cout << ">";
    getline(cin, userInput);

    while (userInput != "quit") {
        CommandParams parsedInput = UserInputParser::parse(userInput);
        cout << "> ";
        getline(cin, userInput);
    }

    return 0;
}