#include "ConfigFileParser.h"
#include "Airplane.h"
#include "RowPricing.h"
using namespace std;

vector<Airplane*> ConfigFileParser::parseFile(const string& filename) {
    vector<Airplane*> airplanes;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        exit(1);
    }

    int numberOfRecords;
    file >> numberOfRecords;
    file.ignore();

    for (int i = 0; i < numberOfRecords; i++) {
        string line;
        getline(file, line);

        stringstream ss(line);

        string date, flightNumber;
        int numberOfColumns;
        vector<RowPricing> rowPrices;
        int start, end, price;
        char dollarSign;

        ss >> date >> flightNumber >> numberOfColumns;

        while (ss >> start) {
            ss.ignore(1, '-');
            ss >> end >> price >> dollarSign;

            rowPrices.push_back({start, end, price});
        }

        Airplane* airplane = new Airplane(date, flightNumber, numberOfColumns, rowPrices);
        airplanes.push_back(airplane);  // Store the pointer to the airplane object
    }

    file.close();

    return airplanes;
}