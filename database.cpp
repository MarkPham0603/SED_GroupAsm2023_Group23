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
// Remove Motorbike from list
void Database::removeMotorbikeFromList(Motorbike &motorbike)
{
    for (auto i = listOfMotorbikeForRent.begin(); i != listOfMotorbikeForRent.end(); i++)
    {
        // Check for owner name
        if (i->getOwner() == motorbike.getOwner())
        {
            listOfMotorbikeForRent.erase(i);
        }
    }
}

// add a request to the list
void Database::addRequestToList(Request &request)
{
    listOfRequests.push_back(request);
}

// Accept a request
void Database::acceptRequestsFromList(Request &request)
{
    for (auto i = listOfRequests.begin(); i != listOfRequests.end(); i++)
    {
        // Check the requestee in the list
        if (i->requestee == request.requestee)
        {
            // Check the requester in the list
            if (i->requester == request.requester)
            {
                //Accept request
                i->status = "Accepted";
            }
            else
            {
                // Decline request
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

// Define getListOfMember
vector<Member> &Database::getListOfMember()
{
    return listOfMember;
}

// Define getListOfRequest
vector<Request> &Database::getListOfRequest()
{
    return listOfRequests;
}

// Define viewAllMotorbikeForGuest
void Database::viewAllMotorbikeForGuest()
{
    // Check if the motorbike list is empty
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