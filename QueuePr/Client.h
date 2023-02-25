#pragma once
#include <iostream>
class Client
{
	std::string name;
	int priority;
	int countPage;
	double time;

public:
	Client() : name{ "/" }, priority{ 30 }, time{ 0 } {}
	Client(std::string _name) : name{ _name }, priority{ 30 }, time{ 0 } {}
	Client(const char* _name) : name{ _name }, priority{ 30 }, time{ 0 } {}

	int getPriority() { return priority; }
	void setPrioritet(int pr) { priority = pr; }
	void setPage(int pg) { countPage = pg; }
	int getPage() { return countPage; }
	void setTime(double _time) { time = _time; }
	std::string getName() { return name; }
	void ShowStatus()
	{
		std::cout << "Name-> " << name << std::endl;
		std::cout << "Time-> " << time << "min" << std::endl;
		std::cout << "Page-> " << countPage << std::endl;
	}
	friend std::ostream& operator<<(std::ostream& output, Client c)
	{

		output << "Name: "<< c.name  <<  " |Page: " << c.countPage << " |Time: " << c.time;
		return output;
	}
};
