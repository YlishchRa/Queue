
#pragma once
#include <iostream>
using namespace std;
template <typename T>
class History {
    T* historyArr;
    int length;
    int MAXlength;

public:
    History(int _MAXlength) : historyArr{new T[_MAXlength]}, MAXlength{_MAXlength}, length{0} {}

    bool isFull() { return length + 1 == MAXlength; }
    void Clear() { length = 0; }

    void AddToHistory(const T& object)
    {
        if (!isFull()) {
            historyArr[length] = object;
            length++;
        }
        else {
            std::cout << "History is full\n";
        }
    }
    void ShowHistory()
    {
        for (int i = 0; i < length; i++) {
            cout << i + 1 << ". " << historyArr[i] << endl;
        }
    }
};
