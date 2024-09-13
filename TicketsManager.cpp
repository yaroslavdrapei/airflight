#include "TicketsManager.h"

TicketsManager::TicketsManager() {}

TicketsManager::~TicketsManager() {
    for (auto& ticket : tickets) {
        delete ticket.second;
    }
}

TicketsManager::TicketsManager(unordered_map<string, Ticket*> tickets) : tickets(tickets) {}

Ticket* TicketsManager::findById(const string &id) {
    if (tickets.find(id) != tickets.end()) {
        return tickets[id];
    }

    return nullptr;
}

vector<Ticket*> TicketsManager::findByUsername(const string &username) {
    vector<Ticket*> result;

    for (auto& pair : tickets) {
        Ticket* ticket = pair.second;
        if (ticket->getUsername() == username) {
            result.push_back(ticket);
        }
    }

    return result;
}

void TicketsManager::add(Ticket *ticket) {
    if (findById(ticket->getId()) != nullptr) {
        cout << "Debug info: not booked (this ID already exists)" << endl;
        return;
    }

    tickets[ticket->getId()] = ticket;
}

void TicketsManager::remove(const string &id) {
    tickets.erase(id);
}
