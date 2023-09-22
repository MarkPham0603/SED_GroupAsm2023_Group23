#include <iostream>
#include <string>
#include "motorbike.h"
using namespace std;

// View motorbike models
void Motorbike::viewmotorInfo()
{
    cout << "Model: " << model << endl;
    cout << "Engine size: " << engineSize << endl;
    cout << "Transmission mode: " << transMode << endl;
    cout << "Manufactured year: " << yearMade << endl;
    cout << "Description: " << description << endl;
    cout << "Credit point cost: " << pointCost << endl;
    cout << "Minimum rent rating: " << minrentRating << endl;
    cout << "Available day: " << rent_day << endl;
    cout << "Status: " << rent_status << endl;
    cout << "Location: " << city << endl;
}

// Get owner's username
string &Motorbike::getUsername()
{
    return username;
}