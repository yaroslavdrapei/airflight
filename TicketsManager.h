#pragma once

#include <unordered_map>
#include <vector>
#include "Ticket.h"
using namespace std;

class TicketsManager {
private:
    unordered_map<string, Ticket*> tickets;
public:

    TicketsManager();
    TicketsManager(unordered_map<string, Ticket*> tickets);

    Ticket* findById(const string& id);
    vector<Ticket*> findByUsername(const string& username);
    void add(Ticket* ticket);
    void remove(const string& id);
};