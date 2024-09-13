#pragma once

#include <vector>
#include "Airplane.h"
using namespace std;

class AirplanesManager {
private:
    vector<Airplane*> airplanes;
public:
    AirplanesManager(vector<Airplane*> airplanes);
    ~AirplanesManager();
    Airplane* findAirplaneByDateAndFlightNumber(const string& date, const string& flightNumber);
};