// COMSC-210 | Lab 32 | Joaquin Felix

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int NUM_LANES = 4;

int main ()
{
    
    deque<Car> lane[NUM_LANES];

    srand(time(0));

    // Intial population
    for (int i = 0; i < NUM_LANES; i++)
    {
        lane[i].push_back(Car());
    }

    //cout << "Initial queue:\n";
    for (int i = 0; i < NUM_LANES; i++)
    {
        cout << "Lane " << i + 1 << ":\n";
        for(auto car : lane[i])
        {
            car.print();
        }
    }
    
    /*int time = 1;

    while (!lane.empty())
    {
        int chance = rand() % 100;

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
            cout << "    Empty\n";
        }
        else
        {
            for (auto car : lane)
            {
                car.print();
            }
        }

        time++;
    }*/
    

    return 0;
}