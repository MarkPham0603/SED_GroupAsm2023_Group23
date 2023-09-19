#include <iostream>
#include <vector>
#include "database.h"
#include "motorbike.h"
using namespace std;

void Database::addMemberToList(Member &new_member)
{
    listOfMember.push_back(new_member);
}

void Database::addMotorbikeToList(Motorbike &new_motorbike)
{
    listOfMotorbikeForRent.push_back(new_motorbike);
}

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