#include <iostream>
#include "ConfigFileParser.h"
using namespace std;

int main() {
    vector<Airplane*>* airplanes = ConfigFileParser::parseFile(R"(E:\KSE\year-2\oop\booking\config.txt)");
    for (auto airplane : *airplanes) {
        cout << airplane->getDate() << " " << airplane->getFlightNumber() << endl;
    }
    return 0;
}