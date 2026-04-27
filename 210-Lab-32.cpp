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

    
    const int INITIAL_SIZE = 2;

    for (int i = 0; i < NUM_LANES; i++)
    {
        for(int j = 0; j < INITIAL_SIZE; j++)
        {
            lane[i].push_back(Car()); 
        }
    }

    cout << "Initial queue:\n";
    for (int i = 0; i < NUM_LANES; i++)
    {
        cout << "Lane " << i + 1 << ":\n";
        for(auto car : lane[i])
        {
            car.print();
        }
    }
    
    
    

    return 0;
}