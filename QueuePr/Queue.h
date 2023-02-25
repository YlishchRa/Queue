#pragma once
#include "Client.h"
#include "History.h"
#include <iostream>
class Queue {
    Client* clients = new Client[500];

    int priority[500];
    int lengthQueue;
    int MAXQueue;
    int MINQueue;

public:
    Queue(int _MAXQueue);
    Queue();
    bool isEmpty();
    bool isFull();
    int getMaxQueue();
    int getLengthQueue();
    void push(Client& cl);

    Client extract();

    Client& getFistInQueue();
    friend std::ostream& operator<<(std::ostream& output, Queue& q);
};
