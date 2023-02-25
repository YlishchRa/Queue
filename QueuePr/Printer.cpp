#include "Printer.h"
#include <chrono>
#include <iostream>
#include <thread>
Printer::Printer(int countClients) : queue{countClients}, history{500} {}

void Printer::AddClientToQueue(Client& client)
{
    queue.push(client);
    std::cout << "Client was add\n";
}
void Printer::Printing()
{
    for (size_t i = queue.getLengthQueue(); i > 0; i--) {
        auto start = std::chrono::steady_clock::now();
        std::this_thread::sleep_for(std::chrono::seconds(queue.getFistInQueue().getPage()));
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;

        queue.getFistInQueue().setTime(elapsed_seconds.count());

        std::cout << "Client: " << queue.getFistInQueue().getName() << " printed.\n";
        history.AddToHistory(queue.getFistInQueue());
        queue.extract();
    }

    std::cout << "All clients was printed\n";
}
void Printer::ShowHistory()
{
    cout << "History of printer: \n";
    history.ShowHistory();
}
