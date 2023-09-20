#include <iostream>
#include <string>
#include "motorbike.h"
using namespace std;

// View motorbike models
void Motorbike::viewmotorInfo()
{
    cout << "Motorbike Model: " << model << endl;
    cout << "Engine Size: " << engineSize << endl;
    cout << "Transmission Model: " << transMode << endl;
    cout << "Production Year: " << yearMade << endl;
    cout << "Description: " << description << endl;
    cout << "Point Cost: " << pointCost << endl;
    cout << "Location: " << city << endl;
}