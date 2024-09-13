#include "../include/UserInputParser.h"
using namespace std;

CommandParams UserInputParser::parse(const std::string &userInput) {
    CommandParams result;
    stringstream ss(userInput);

    ss >> result.command;
    string param;

    while (ss >> param) {
        result.params.push_back(param);
    }

    return result;
}