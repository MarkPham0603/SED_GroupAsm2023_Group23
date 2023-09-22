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
    cout << "Minimum request rating: " << minRequestRating << endl;
    cout << "Available day: " << rent_day << endl;
    cout << "Status: " << rent_status << endl;
    cout << "Location: " << city << endl;
}

// Get owner's username
string &Motorbike::getOwner()
{
    return owner;
}

// Getter for model
string &Motorbike::getModel() {
    return model;
}

// Getter for engineSize
int &Motorbike::getEngineSize(){
    return engineSize;
}

// Getter for transMode
string &Motorbike::getTransMode(){
    return transMode;
}

// Getter for yearMade
int &Motorbike::getYearMade(){
    return yearMade;
}

// Getter for description
string &Motorbike::getDescription(){
    return description;
}

// Getter for pointCost
int &Motorbike::getPointCost(){
    return pointCost;
}

// Getter for minrentRating
int &Motorbike::getMinRequestRating(){
    return minRequestRating;
}

// Getter for rent_day
string &Motorbike::getRentDay(){
    return rent_day;
}

// Getter for rent_status
string &Motorbike::getRentStatus(){
    return rent_status;
}

// Getter for city
string &Motorbike::getCity(){
    return city;
}

