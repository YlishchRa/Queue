#include "Queue.h"

Queue::Queue(int _MAXQueue) : MAXQueue{_MAXQueue > 500 ? 500 : _MAXQueue}, MINQueue{0}, lengthQueue{0} {}

Queue::Queue() : MAXQueue{500}, MINQueue{0}, lengthQueue{0} {}

bool Queue::isEmpty()
{
    return lengthQueue == MINQueue;
}

bool Queue::isFull()
{
    return lengthQueue + 1 == MAXQueue;
}

int Queue::getMaxQueue()
{
    return MAXQueue;
}

int Queue::getLengthQueue()
{
    return lengthQueue;
}

void Queue::push(Client& cl)
{
    if (!isFull()) {
        priority[lengthQueue] = cl.getPriority();
        clients[lengthQueue] = cl;
        lengthQueue++;
        for (int i = 0; i < lengthQueue; i++) {
            for (int j = 0; j < lengthQueue; j++) {
                if (priority[j] > priority[i]) {
                    std::swap(priority[j], priority[i]);
                    std::swap(clients[j], clients[i]);
                }
            }
        }
    }
    else {
        std::cout << "Queue is full\n";
    }
}

Client Queue::extract()
{
    Client tmpClient = clients[0];
    for (int i = 0; i < lengthQueue; i++) {
        priority[i] = priority[i + 1];
        clients[i] = clients[i + 1];
    }
    lengthQueue--;
    return tmpClient;
}

Client& Queue::getFistInQueue()
{
    return clients[0];
}

std::ostream& operator<<(std::ostream& output, Queue& q)
{
    for (int i = 0; i < q.getLengthQueue(); i++) {
        output << q.clients[i];
    }
    return output;
}
