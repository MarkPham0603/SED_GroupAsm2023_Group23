#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "motorbike.h"
#include "database.h"
using namespace std;

class Guest
{
private:
    string fullName;
    string phoneNumber;
    string idType;
    string idPassportNumber;
    string driverLicenseNumber;
    string expiryDate;

public:
    // Guest class constructor
    Guest(const string &fullName = "", const string &phoneNumber = "",
          const string &idType = "", const string &idPassportNumber = "",
          const string &driverLicenseNumber = "", const string &expiryDate = "")
        : fullName(fullName), phoneNumber(phoneNumber),
          idType(idType), idPassportNumber(idPassportNumber),
          driverLicenseNumber(driverLicenseNumber), expiryDate(expiryDate){};

    // User enter some personal information for register as Member
    void registerAsMember(Database &database);
    void viewAllMotorbikeForGuest(Database &database);
    friend Member;
};

class Member : public Guest
{
private:
    string username;
    string password;
    int creditPoints;
    Motorbike motorbike;
    bool hasMotorbike;

public:
    // Member class constructor
    Member(const string &username = "", const string &password = "", const int creditPoints = 0,
           const string &fullName = "", const string &phoneNumber = "", const string &idType = "", const string &idPassportNumber = "",
           const string &driverLicenseNumber = "", const string &expiryDate = "")
        : username(username), password(password), Guest(fullName, phoneNumber, idType, idPassportNumber, driverLicenseNumber, expiryDate),
          creditPoints(creditPoints), motorbike(), hasMotorbike(false){};

    void viewInformation(){};
    void listMotorbikeForRent(){};
    void unlistMotorbike(){};
};

class Admin
{
private:
    string username;
    string password;

public:
    // Admin class constructor
    Admin(const string adminUsername, string adminPassword)
        : username(adminUsername), password(adminPassword){};
};

#endif