#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <vector>
#include "users.h"
#include "motorbike.h"
#include "utils.h"
using namespace std;

class Member;
class Utility;

class Database
{
private:
    vector<Member> listOfMember;
    vector<Motorbike> listOfMotorbikeForRent;
public:
    //Database functions declarations
    void addMemberToList(Member &new_member);
    void addMotorbikeToList(Motorbike &new_motorbike);
    vector<Motorbike>& getListOfMotorbikeForRent();
    void viewAllMotorbikeForGuest();
    friend Utility;
};

#endif