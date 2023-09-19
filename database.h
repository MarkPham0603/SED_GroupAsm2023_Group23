#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <vector>
#include "motorbike.h"
using namespace std;

class Member;

class Database
{
private:
    vector<Member> listOfMember;
    vector<Motorbike> listOfMotorbikeForRent;

public:
    void addMemberToList(Member &new_member);
    void addMotorbikeToList(Motorbike &new_motorbike);
    void viewAllMotorbikeForGuest();
};

#endif