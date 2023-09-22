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
    string username, password, fullName, phoneNumber, idType, idPassportNumber, driverLicenseNumber, expiryDate;
    string model, transMode, description, rent_day, rent_status = "Available", city;
    int engineSize = 0, yearMade = 0, pointCost = 0, minRentRating = 0;
    int choice = 0;
    bool hasMotorbike = false;

    cout << "============================================================" << endl;
    while (choice != 1)
    {
        // Define credentials and personal information using user input
        cout << "Set your username: ";
        getline(cin, username);
        cout << "Set your password: ";
        getline(cin, password);
        cout << "Enter your full name: ";
        getline(cin, fullName);
        cout << "Enter your phone number: ";
        getline(cin, phoneNumber);
        cout << "Enter your id type: ";
        getline(cin, idType);
        cout << "Enter your id number: ";
        getline(cin, idPassportNumber);
        cout << "Enter your driver license number: ";
        getline(cin, driverLicenseNumber);
        cout << "Enter the expiry date for the driver license (dd/mm/yyyy): ";
        getline(cin, expiryDate);

        // Asking user if they have a motorbike available for rent
        cout << "============================================================" << endl;
        cout << "Do you have a motorbike to list for rent? (1 for yes, 0 for no): ";
        cin >> choice;
        if (choice == 1)
        {
            // Define motorbike if user has one
            cout << "Enter the model: ";
            getline(cin, model);
            cout << "Enter the engine size: ";
            cin >> engineSize;
            cout << "Enter the transmission mode: ";
            getline(cin, transMode);
            cout << "Enter the manufactured year: ";
            cin >> yearMade;
            cout << "Enter the description of the motorbike: ";
            getline(cin, description);
            cout << "Enter the credit point cost: ";
            cin >> pointCost;
            cout << "Enter the minimum rent rating: ";
            cin >> minRentRating;
            cout << "Enter the day and month available for rent (dd/mm): ";
            getline(cin, rent_day);
            cout << "Enter the location: ";
            getline(cin, city);
            hasMotorbike = true;
        }

        // Display user inputs for user to confirm
        cout << "============================================================" << endl;
        cout << "Your credentials" << endl;
        cout << "----------------" << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "============================================================" << endl;
        cout << "Your personal information" << endl;
        cout << "-------------------------" << endl;
        cout << "Full name: " << fullName << endl;
        cout << "Phone number: " << phoneNumber << endl;
        cout << "ID type: " << idType << endl;
        cout << "ID number: " << idPassportNumber << endl;
        cout << "Driver license number: " << driverLicenseNumber << endl;
        cout << "Expiry date: " << expiryDate << endl;
        cout << "============================================================" << endl;

        // Display user inputs for motorbike if they have one
        if (hasMotorbike)
        {
            cout << "Your motorbike information" << endl;
            cout << "--------------------------" << endl;
            cout << "Model: " << model << endl;
            cout << "Engine size: " << engineSize << endl;
            cout << "Transmission mode: " << transMode << endl;
            cout << "Manufactured year: " << yearMade << endl;
            cout << "Description: " << description << endl;
            cout << "Credit point cost: " << pointCost << endl;
            cout << "Minimum rent rating: " << minRentRating << endl;
            cout << "Available day: " << rent_day << endl;
            cout << "Location: " << city << endl;
            cout << "============================================================" << endl;
        }

        cout << "Is this correct? (1 for yes, 0 for no): ";
        cin >> choice;
        if (choice == 1)
        {
            if (hasMotorbike)
            {
                // Create a new Motorbike and use it in the constructor of the new Member object with user inputs and add them to member list
                Motorbike newMotorbike(username, model, engineSize, transMode, yearMade, description,
                                       pointCost, minRentRating, rent_day, rent_status, city);
                database.addMotorbikeToList(newMotorbike);
            }

            Member newMember(username, password, fullName, phoneNumber,
                             idType, idPassportNumber, driverLicenseNumber, expiryDate, 20, hasMotorbike);
            database.addMemberToList(newMember);

            // Display success message and set flag to exit the loop
            cout << "Registration successful. Welcome, " << username << "!" << endl;
        }
    }
}

void Guest::viewAllMotorbikeForGuest(Database &database)
{
    database.viewAllMotorbikeForGuest();
}

// Define Member class functions
void Member::viewInformation()
{
    cout << "============================================================" << endl;
    cout << "Your credentials" << endl;
    cout << "----------------" << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "============================================================" << endl;
    cout << "Your personal information" << endl;
    cout << "-------------------------" << endl;
    cout << "Full Name: " << fullName << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "ID Type: " << idType << endl;
    cout << "ID/Passport Number: " << idPassportNumber << endl;
    cout << "Driver's License Number: " << driverLicenseNumber << endl;
    cout << "Expiry Date: " << expiryDate << endl;
    cout << "Credit Points: " << creditPoints << endl;
    cout << "Has motorbike for rent: " << hasMotorbike << endl;
}

void Member::listMotorbikeForRent(Database &database)
{
    if (hasMotorbike)
    {
        cout << "You already have a motorbike listed for rent." << endl;
        for (auto &motorbike : database.getListOfMotorbikeForRent())
        {
            if (motorbike.getOwner() == username)
            {
                cout << "Your motorbike information" << endl;
                cout << "--------------------------" << endl;
                motorbike.viewmotorInfo();
            }
        }
    }
    else
    {
        string model, transMode, description, rent_day, rent_status = "Available", city;
        int engineSize = 0, yearMade = 0, pointCost = 0, minRentRating = 0;
        int choice = 0;

        while (choice != 1)
        {
            cout << "Enter the model: ";
            getline(cin, model);
            cout << "Enter the engine size: ";
            cin >> engineSize;
            cout << "Enter the transmission mode: ";
            getline(cin, transMode);
            cout << "Enter the manufactured year: ";
            cin >> yearMade;
            cout << "Enter the description of the motorbike: ";
            getline(cin, description);
            cout << "Enter the credit point cost: ";
            cin >> pointCost;
            cout << "Enter the minimum rent rating: ";
            cin >> minRentRating;
            cout << "Enter the day and month available for rent (dd/mm): ";
            getline(cin, rent_day);
            cout << "Enter the location: ";
            getline(cin, city);
            hasMotorbike = true;

            cout << "============================================================" << endl;
            cout << "Your motorbike information" << endl;
            cout << "--------------------------" << endl;
            cout << "Model: " << model << endl;
            cout << "Engine size: " << engineSize << endl;
            cout << "Transmission mode: " << transMode << endl;
            cout << "Manufactured year: " << yearMade << endl;
            cout << "Description: " << description << endl;
            cout << "Credit point cost: " << pointCost << endl;
            cout << "Minimum rent rating: " << minRentRating << endl;
            cout << "Start time: " << rent_day << endl;
            cout << "Location: " << city << endl;
            cout << "============================================================" << endl;
            cout << "Is this correct? (1 for yes, 0 for no): ";
            cin >> choice;
            if (choice == 1)
            {
                Motorbike newMotorbike(username, model, engineSize, transMode, yearMade, description,
                                       pointCost, minRentRating, rent_day, rent_status, city);
                database.addMotorbikeToList(newMotorbike);
                cout << "\nYour listing has been posted successfully.";
            }
            else
            {
                cout << "Do you want to quit? (1 for yes, 0 for no): ";
                cin >> choice;
                if (choice == 1)
                {
                    cout << "Your listing request has been canceled." << endl;
                }
            }
        }
    }
}

void Member::unlistMotorbike(Database &database)
{
    if (!hasMotorbike)
    {
        cout << "You don't have a motorbike listed for rent." << endl;
    }
    else
    {
        for (auto &motorbike : database.getListOfMotorbikeForRent())
        {
            if (motorbike.getOwner() == username)
            {
                int choice;

                cout << "Your motorbike information" << endl;
                cout << "--------------------------" << endl;
                motorbike.viewmotorInfo();
                cout << "Do you want to unlist this motorbike (1 for yes, 0 for no): ";
                cin >> choice;
                if (choice == 1)
                {
                    hasMotorbike = false; // Mark that the member no longer has a listed motorbike
                    cout << "Your motorbike has been unlisted." << endl;
                }
                else
                    cout << "Your unlist request has been canceled." << endl;
            }
        }
    }
}
