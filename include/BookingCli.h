#pragma once

#include "CommandParams.h"
#include "Airplane.h"
#include "Ticket.h"
#include "AirplanesManager.h"
#include "TicketsManager.h"
using namespace std;

class BookingCli {
private:
    vector<string> params;
    AirplanesManager airplanesManager;
    TicketsManager bookedTicketsManager;


    void viewById(const string& id);
    void viewByUsername(const string& username);
    void viewByDateAndFlight(const string& date, const string& flightNumber);
public:
    BookingCli(AirplanesManager& airplanesManager, TicketsManager& bookedTicketsManager);

    vector<string> getParams();
    void setParams(const CommandParams& newParams);

    void checkCommand();
    void bookCommand();
    void returnCommand();
    void viewCommand();
};


