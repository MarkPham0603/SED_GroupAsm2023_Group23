#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME
#include <iostream>
#include <string>s
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
    Guest(string fullName = "", string phoneNumber = "",
          string idType = "", string idPassportNumber = "",
          string driverLicenseNumber = "", string expiryDate = "")
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
    int creditPoints;
    Motorbike motorbike;
    bool hasMotorbike;

public:
    // Member constructor
    Member(const string &fullName, const string &phoneNumber,
           const string &idType, const string &idPassportNumber,
           const string &driverLicenseNumber, const string &expiryDate,
           const string &username, int creditPoints = 20)
        : Guest(fullName, phoneNumber, idType, idPassportNumber, driverLicenseNumber, expiryDate),
          username(username), creditPoints(20), motorbike(motorbike), hasMotorbike(false){};

    void viewInformation()
    {
        cout << "Username: " << username << endl;
        cout << "Full Name: " << fullName << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "ID Type: " << idType << endl;
        cout << "ID/Passport Number: " << idPassportNumber << endl;
        cout << "Driver's License Number: " << driverLicenseNumber << endl;
        cout << "Expiry Date: " << expiryDate << endl;
        cout << "Credit Points: " << creditPoints << endl;
        motorbike.viewmotorInfo();
    }

    void listMotorbikeForRent()
    {
        if (!hasMotorbike)
        {
            cout << "You don't have a motorbike to list for rent." << endl;
        }
        else
        {
            cout << "Your Motorbike for Rent:" << endl;
            motorbike.viewmotorInfo();
        }
    }

    void unlistMotorbike()
    {
        if (!hasMotorbike)
        {
            cout << "You don't have a motorbike listed for rent." << endl;
        }
        else
        {
            cout << "Unlisting your Motorbike for Rent:" << endl;
            motorbike.viewmotorInfo(); // Display the details of the motorbike being unlisted
            hasMotorbike = false;      // Mark that the member no longer has a listed motorbike
            cout << "Your motorbike has been unlisted." << endl;
        }
    }

    friend Guest;
};

class Admin
{
private:
    string username;
    string password;

public:
    Admin(const string adminUsername, string adminPassword)
        : username(adminUsername), password(adminPassword){};
};

#endif