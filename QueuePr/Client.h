#pragma once
#include <iostream>
class Client {
    std::string name;
    int priority;
    int countPage;
    double time;

public:
    Client();
    Client(std::string _name);
    Client(const char* _name);

    int getPriority();
    void setPrioritet(int pr);
    void setPage(int pg);
    int getPage();
    void setTime(double _time);
    std::string getName();
    void ShowStatus();
    friend std::ostream& operator<<(std::ostream& output, Client c);
};
