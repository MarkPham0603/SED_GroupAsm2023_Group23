#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <vector>
#include "users.h"
#include "motorbike.h"
#include "utils.h"
#include "request.h"
using namespace std;

class Member;
class Motorbike;
class Utility;

class Database
{
private:
    vector<Member> listOfMember;
    vector<Motorbike> listOfMotorbikeForRent;
    vector<Request> listOfRequests; 
public:
    //Database functions declarations
    void addMemberToList(Member &new_member);
    void addMotorbikeToList(Motorbike &new_motorbike);
    void removeMotorbikeFromList(Motorbike &motorbike);
    vector<Motorbike>& getListOfMotorbikeForRent();
    vector<Member>& getListOfMember();
    vector<Request>& getListOfRequest();
    void viewAllMotorbikeForGuest();
    friend Utility;
};

#endif