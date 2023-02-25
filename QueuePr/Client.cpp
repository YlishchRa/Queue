#include "Client.h"

Client::Client() : name{"/"}, priority{30}, time{0} {}

Client::Client(std::string _name) : name{_name}, priority{30}, time{0} {}

Client::Client(const char* _name) : name{_name}, priority{30}, time{0} {}

int Client::getPriority()
{
    return priority;
}

void Client::setPrioritet(int pr)
{
    priority = pr;
}

void Client::setPage(int pg)
{
    countPage = pg;
}

int Client::getPage()
{
    return countPage;
}

void Client::setTime(double _time)
{
    time = _time;
}

std::string Client::getName()
{
    return name;
}

void Client::ShowStatus()
{
    std::cout << "Name-> " << name << std::endl;
    std::cout << "Time-> " << time << "min" << std::endl;
    std::cout << "Page-> " << countPage << std::endl;
}

std::ostream& operator<<(std::ostream& output, Client c)
{
    output << "Name: " << c.name << " |Page: " << c.countPage << " |Time : " << c.time << "s";
    return output;
}
