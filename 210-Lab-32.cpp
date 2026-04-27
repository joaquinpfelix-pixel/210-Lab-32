// COMSC-210 | Lab 32 | Joaquin Felix

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

// Constants
const int NUM_LANES = 4;
const int INITIAL_SIZE = 2;
const int TIME_LIMIT = 20;

// Probabilities
const int PROB_PAY = 46;
const int PROB_JOIN = 39;

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

            if (lanes[i].empty())
            {
                if(chance < 50)
                {
                    Car newCar;
                    cout << "Joined: ";
                    newCar.print();
                    lanes[i].push_back(newCar);
                }
                else
                {
                    cout << "Idle\n";
                }
            }
            else
            {
                if (chance < PROB_PAY)
                {
                    cout << "Paid: ";
                    lanes[i].front().print();
                    lanes[i].pop_front();
                }
                else if (chance < PROB_PAY + PROB_JOIN)
                {
                    Car newCar;
                    cout << "Joined: ";
                    newCar.print();
                    lanes[i].push_back(newCar);
                }
                else
                {
                    Car movingCar = lanes[i].back();
                    lanes[i].pop_back();

                    int newLane;
                    do
                    {
                        newLane = rand() % NUM_LANES;
                    } while (newLane == i);
                    
                    lanes[newLane].push_back(movingCar);

                    cout << "Switched: ";
                    movingCar.print();
                    
                }
            }
        }

        for (int i = 0; i <NUM_LANES; i++)
        {
            cout << "Lane: " << i + 1 << " Queue:\n";

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