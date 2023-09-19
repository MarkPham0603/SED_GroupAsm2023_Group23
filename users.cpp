#include <iostream>
#include <string>
#include "motorbike.h"
#include "database.h"
#include "users.h"
using namespace std;

// Define Guest class functions
// User enter some personal information for register as Member
void Guest::registerAsMember(Database &database)
{
    string username;

    // User input
    cout << "Set your username: ";
    getline(cin, username);
    cout << "Enter full name: ";
    getline(cin, fullName);
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);
    cout << "Enter type of id: ";
    getline(cin, idType);
    cout << "Enter id number: ";
    getline(cin, idPassportNumber);
    cout << "Enter driver license number: ";
    getline(cin, driverLicenseNumber);
    cout << "Enter expiry date for driver license: ";
    getline(cin, expiryDate);

    // Create a new Member object that contain the user input
    Member newMember(username, fullName, phoneNumber, idType, idPassportNumber, driverLicenseNumber, expiryDate);
    database.addMemberToList(newMember);
    cout << "Registration successful. Welcome, " << username << "!" << endl;
}

void Guest::viewAllMotorbikeForGuest(Database &database)
{
    database.viewAllMotorbikeForGuest();
}

// Define Member class functions
void Member::viewInformation()
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

void Member::listMotorbikeForRent()
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

void Member::unlistMotorbike()
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

