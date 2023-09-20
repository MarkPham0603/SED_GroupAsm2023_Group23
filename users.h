#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "motorbike.h"
#include "database.h"
#include "utils.h"
using namespace std;

class Database;
class Utility;

class Guest
{
public:
    // User enter some personal information for register as Member
    void registerAsMember(Database& database);
    void viewAllMotorbikeForGuest(Database& database);
};

class Member : public Guest
{
private:
    string username;
    string password;
    string fullName;
    string phoneNumber;
    string idType;
    string idPassportNumber;
    string driverLicenseNumber;
    string expiryDate;
    int creditPoints;
    Motorbike motorbike;
    bool hasMotorbike;

public:
    // Member class constructor
    Member(const string &username = "", const string &password = "",
           const string &fullName = "", const string &phoneNumber = "", const string &idType = "", const string &idPassportNumber = "",
           const string &driverLicenseNumber = "", const string &expiryDate = "",
           const int creditPoints = 0, const Motorbike &motorbike = Motorbike(), const bool hasMotorbike = false)
        : username(username), password(password),
          fullName(fullName), phoneNumber(phoneNumber), idType(idType), idPassportNumber(idPassportNumber),
          driverLicenseNumber(driverLicenseNumber), expiryDate(expiryDate),
          creditPoints(creditPoints), motorbike(motorbike), hasMotorbike(hasMotorbike){};
    void viewInformation();
    void listMotorbikeForRent(Database& database);
    void unlistMotorbike();
    friend Database;
    friend Utility;
};

class Admin
{
private:
    string username;
    string password;
public:
    // Admin class constructor
    Admin(const string &adminUsername, string &adminPassword)
        : username(adminUsername), password(adminPassword){};
};

#endif