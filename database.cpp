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

void Database::removeMotorbikeFromList(Motorbike &motorbike)
{
    for (auto i = listOfMotorbikeForRent.begin(); i != listOfMotorbikeForRent.end(); i++)
    {
        if (i->getOwner() == motorbike.getOwner())
        {
            listOfMotorbikeForRent.erase(i);
        }
    }
}

void Database::addRequestToList(Request &request)
{
    listOfRequests.push_back(request);
}

void Database::acceptRequestsFromList(Request &request)
{
    for (auto i = listOfRequests.begin(); i != listOfRequests.end(); i++)
    {
        if (i->requestee == request.requestee)
        {
            if (i->requester == request.requester)
            {
                i->status = "Accepted";
            }
            else
            {
                listOfRequests.erase(i);
            }
        }
    }
}

// Define getListOfMotorbikeForRent
vector<Motorbike> &Database::getListOfMotorbikeForRent()
{
    return listOfMotorbikeForRent;
}

vector<Member> &Database::getListOfMember()
{
    return listOfMember;
}

vector<Request> &Database::getListOfRequest()
{
    return listOfRequests;
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
        for (size_t i = 0; i < listOfMotorbikeForRent.size(); i++)
        {
            listOfMotorbikeForRent[i].viewmotorInfo();
        }
    }
}