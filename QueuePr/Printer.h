#pragma once
#include "Client.h"
#include "Queue.h"
#include <chrono>
#include <iostream>
#include <thread>
class Printer
{
    Queue queue;

public:
    Printer(int countClients) : queue{countClients} {}
    void AddClientToQueue(Client& client)
    {
        queue.push(client);
        std::cout << "Client was add\n";
    }
    void Printing(Client* clients)
    {
        for (size_t i = queue.getLengthQueue(); i > 0; i--)
        {
            std::this_thread::sleep_for(
                std::chrono::seconds(queue.getFistInQueue().getPage()));
            clients->setTime(queue.getFistInQueue().getPage());
            std::cout << "Client printed. "
                      << queue.getFistInQueue().getPage();
            std::cout << "minutes have passed. \t" << queue.extract() << std::endl;
        }

        std::cout << "All clients was printed\n";
    }
};
