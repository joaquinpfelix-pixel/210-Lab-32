// COMSC-210 | Lab 32 | Joaquin Felix

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int NUM_LANES = 4;
const int INITIAL_SIZE = 2;
const int TIME_LIMIT = 20;

int main ()
{
    
    deque<Car> lanes[NUM_LANES];

    srand(time(0));

    //Populate lanes
    for (int i = 0; i < NUM_LANES; i++)
    {
        for(int j = 0; j < INITIAL_SIZE; j++)
        {
            lanes[i].push_back(Car()); 
        }
    }

    cout << "Initial queue:\n";
    for (int i = 0; i < NUM_LANES; i++)
    {
        cout << "Lane " << i + 1 << ":\n";
        for(auto car : lanes[i])
        {
            car.print();
        }
    }
    
    for (int time = 1; time <=TIME_LIMIT; time++)
    {
        cout << "\nTime: " << time << endl;
        
        for (int i = 0; i < NUM_LANES; i++)
        {
            int chance = rand() % 100;

            cout << "Lane " << i + 1 << " ";

            if (!lanes[i].empty())
            {
                if(chance < 50)
                {
                    cout << "Paid: ";
                    lanes[i].front().print();
                    lanes[i].pop_front();
                }
                else
                {
                    Car newCar;
                    cout << "Joined: ";
                    newCar.print();
                    lanes[i].push_back(newCar);
                }
            }
            else
            {
                if (chance < 50)
                {
                    Car newCar;
                    cout << "Joined: ";
                    newCar.print();
                    lanes[i].push_back(newCar);
                }
                else
                {
                    cout << "No action\n";
                }
            }
        }

        for (int i = 0; i <NUM_LANES; i++)
        {
            cout << "Lane " << i + 1 << " Queue:\n";

            if (lanes[i].empty())
            {
                cout << "    Empty\n";
            }
            else
            {
                for (auto car : lanes[i])
                {
                    car.print();
                } 
            }
        }
    }
    

    return 0;
}