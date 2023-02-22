#include <iostream>
#include "Printer.h"
using namespace std;
int globalID = 0;
void CreateClient(const char* name, int prioirty, int page, Client* clients, Printer& printer)
{
	clients[globalID] = name;
	clients[globalID].setPage(page);
	clients[globalID].setPrioritet(prioirty);
	printer.AddClientToQueue(clients[globalID]);
	globalID++;
}
int main()
{

	Printer printer(10);
	Client clients[5];

	CreateClient("Yura", 1, 3, clients, printer);
	CreateClient("Olga", 3, 5, clients, printer);
	CreateClient("Sasha", 4, 1, clients, printer);
	CreateClient("Nastya", 4, 7, clients, printer);
	CreateClient("Tetyana", 3, 4, clients, printer);
	


	printer.Printing(clients);

	clients[0].ShowStatus();

	return 0;
}