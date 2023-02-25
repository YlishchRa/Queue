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

	CreateClient("Yura", 1, 1, clients, printer);
	CreateClient("Olga", 3, 1, clients, printer);
	CreateClient("Sasha", 4, 1, clients, printer);
	CreateClient("Nastya", 4, 1, clients, printer);
	CreateClient("Tetyana", 3, 1, clients, printer);
	


	printer.Printing();

	
	printer.ShowHistory();

	return 0;
}