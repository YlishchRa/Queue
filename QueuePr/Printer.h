#pragma once
#include "Client.h"
#include "Queue.h"
class Printer {
    Queue queue;
    History<Client> history;

public:
    Printer(int countClients);
    void AddClientToQueue(Client& client);
    void Printing();
    void ShowHistory();
};
