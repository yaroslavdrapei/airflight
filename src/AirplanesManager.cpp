#include "../include/AirplanesManager.h"

AirplanesManager::AirplanesManager(vector<Airplane*> airplanes) : airplanes(airplanes){}

AirplanesManager::~AirplanesManager() {
    for (auto airplane : airplanes) {
        delete airplane;
    }
};

Airplane *AirplanesManager::findAirplaneByDateAndFlightNumber(const string &date, const string &flightNumber) {
    for (auto airplane: airplanes) {
        if ((airplane->getFlightNumber() == flightNumber) && (airplane->getDate() == date)) {
            return airplane;
        }
    }

    return nullptr;
}
