// COMSC-210 | Lab 32 | Joaquin Felix

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

int main ()
{
    const int INITIAL_SIZE = 2;

    deque<Car> lane;

    srand(time(0));

    // Intial population
    for (int i = 1; i <= INITIAL_SIZE; i++)
    {
        lane.push_back(Car());
    }

    cout << "Initial lane:\n";
    for (auto car : lane)
    {
        car.print();
    }
    
    int time = 1;

    while (!lane.empty())
    {
        int chance = rand() % 50;

        cout << "\nTime: " << time << " ";

        if (chance < 55)
        {
            cout << "Operation: Car paid: ";
            lane.front().print();
            lane.pop_front();
        }
        else
        {
            Car newCar;
            cout << "Operation: Joined lane: ";
            newCar.print();
            lane.push_back(newCar);
        }

        cout << "Queue:\n";
        if (lane.empty())
        {
            cout << "   Empty\n";
        }
        else
        {
            for (auto car : lane)
            {
                car.print();
            }
        }

        time++;
    }
    

    return 0;
}