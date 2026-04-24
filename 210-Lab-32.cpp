// COMSC-210 | Lab 32 | Joaquin Felix

#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

int main ()
{
    const int INITIAL_SIZE = 2;

    deque<Car> lane;

    for (int i = 1; i <= INITIAL_SIZE; i++)
    {
        lane.push_back(Car());
    }

    cout << "Initial queue:\n";
    for (auto car : lane)
    {
        car.print();
    }

    cout << "\nRemoving one car (front)...\n";
    lane.pop_front();

    cout << "Queue after pop:\n";
    for (auto car : lane)
    {
        car.print();
    }

    return 0;
}