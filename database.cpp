#include <iostream>
#include <vector>
#include "database.h"
#include "motorbike.h"
#include "utils.h"
#include "users.h"
using namespace std;

// Define addMemberToList
void Database::addMemberToList(Member &new_member)
{
    listOfMember.push_back(new_member);
}

// Define addMotorbikeToList
void Database::addMotorbikeToList(Motorbike &new_motorbike)
{
    listOfMotorbikeForRent.push_back(new_motorbike);
}

// Define getListOfMotorbikeForRent
vector<Motorbike>& Database::getListOfMotorbikeForRent()
{
    return listOfMotorbikeForRent;
}

// Define viewAllMotorbikeForGuest
void Database::viewAllMotorbikeForGuest()
{
    if (listOfMotorbikeForRent.empty())
    {
        cout << "No motorbikes are available for rent at this time.\n";
    }
    else
    {
        for (size_t i = 0; i < listOfMotorbikeForRent.capacity(); i++)
        {
            listOfMotorbikeForRent[i].viewmotorInfo();
        }
    }
}