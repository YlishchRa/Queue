#pragma once
#include "Client.h"
#include <iostream>
class Queue
{
    Client* clients = new Client[500];
    int priority[500];
    int lengthQueue;
    int MAXQueue;
    int MINQueue;

public:
    Queue(int _MAXQueue) : MAXQueue{_MAXQueue > 500 ? 500 : _MAXQueue}, MINQueue{0}, lengthQueue{0} {};
    Queue() : MAXQueue{500}, MINQueue{0}, lengthQueue{0} {};
    bool isEmpty() { return lengthQueue == MINQueue; }
    bool isFull() { return lengthQueue + 1 == MAXQueue; }
    int getMaxQueue() { return MAXQueue; }
    int getLengthQueue() { return lengthQueue; }
    void push(Client& cl)
    {

        if (!isFull())
        {
            priority[lengthQueue] = cl.getPriority();
            clients[lengthQueue] = cl;
            lengthQueue++;
            for (int i = 0; i < lengthQueue; i++)
            {
                for (int j = 0; j < lengthQueue; j++)
                {
                    if (priority[j] > priority[i])
                    {
                        std::swap(priority[j], priority[i]);
                        std::swap(clients[j], clients[i]);
                    }
                }
            }
        }
        else
        {
            std::cout << "Queue is full\n";
        }
    }
    Client extract()
    {
        Client tmpClient = clients[0];
        for (int i = 0; i < lengthQueue; i++)
        {
            priority[i] = priority[i + 1];
            clients[i] = clients[i + 1];
        }

        lengthQueue--;
        return tmpClient;
    }
    Client getFistInQueue() { return clients[0]; }
    friend std::ostream& operator<<(std::ostream& output, Queue& q)
    {

        for (int i = 0; i < q.getLengthQueue(); i++)
        {
            output << q.clients[i];
        }
        return output;
    }
};
