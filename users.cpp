#include <iostream>
#include <string>
#include "motorbike.h"
#include "database.h"
#include "users.h"
#include "request.h"
using namespace std;

// Define Guest class functions
// User enter some personal information for register as Member
void Guest::registerAsMember(Database &database)
{
    string username, password, fullName, phoneNumber, idType, idPassportNumber, driverLicenseNumber, expiryDate;
    string model, transMode, description, rent_day, rent_status = "Available", city;
    int engineSize = 0, yearMade = 0, pointCost = 0, minRequestRating = 0;
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
            cin >> minRequestRating;
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
            cout << "Minimum rent rating: " << minRequestRating << endl;
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
                                       pointCost, minRequestRating, rent_day, rent_status, city);
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
// View Member information
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

// Member can list motorbike for rent
void Member::listMotorbikeForRent(Database &database)
{
    // Check if the member already has a motorbike or not
    if (hasMotorbike)
    {
        cout << "You already have a motorbike listed for rent." << endl;
        for (auto &motorbike : database.getListOfMotorbikeForRent())
        {
            // Check if the motorbike owner is match with Member username
            if (motorbike.getOwner() == username)
            {
                cout << "Your motorbike information" << endl;
                cout << "--------------------------" << endl;
                motorbike.viewmotorInfo();
            }
        }
    }
    // if not, member can provide information for new motorbike and add to the list
    else
    {
        string model, transMode, description, rent_day, rent_status = "Available", city;
        int engineSize = 0, yearMade = 0, pointCost = 0, minRequestRating = 0;
        int choice = 0;

        while (choice != 1)
        {
            // Member enter motor information
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
            cin >> minRequestRating;
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
            cout << "Minimum rent rating: " << minRequestRating << endl;
            cout << "Start time: " << rent_day << endl;
            cout << "Location: " << city << endl;
            cout << "============================================================" << endl;
            cout << "Is this correct? (1 for yes, 0 for no): ";
            cin >> choice;
            if (choice == 1)
            {
                // Create new motorbike object and add to the list
                Motorbike newMotorbike(username, model, engineSize, transMode, yearMade, description,
                                       pointCost, minRequestRating, rent_day, rent_status, city);
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

// Member can unlist motorbike
void Member::unlistMotorbike(Database &database)
{
    // Check if the member already has a motorbike or not
    if (!hasMotorbike)
    {
        cout << "You don't have a motorbike listed for rent." << endl;
    }
    else
    {
        // Loop through the database of Motorbike List
        for (auto &motorbike : database.getListOfMotorbikeForRent())
        {
            // Check if the motorbike owner is match with Member username
            if (motorbike.getOwner() == username)
            {
                // Check for the motorbike status
                if (motorbike.getRentStatus() == "Rented")
                {
                    cout << "Sorry! You can't unlist a motorbike while that motorbike is being rented.\n";
                }
                else
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
}

void Member::searchMotorbyCity(Database &database)
{
    string city;
    cout << "Enter the city to search for available motorbikes: ";
    cin >> city;

    // Display available motorbikes in the specified city
    cout << "Available motorbikes in " << city << ":" << endl;
    cout << "----------------------------------" << endl;

    for (Motorbike &motorbike : database.getListOfMotorbikeForRent())
    {
        // Check for the city and status
        if (motorbike.getCity() == city && motorbike.getRentStatus() == "Available" && motorbike.getMinRequestRating() <= request_rating)
        {
            cout << "Owner: " << motorbike.getOwner() << endl;
            cout << "Motorbike Model: " << motorbike.getModel() << endl;
            cout << "Engine Size: " << motorbike.getEngineSize() << "cc" << endl;
            cout << "Transmission Model: " << motorbike.getTransMode() << endl;
            cout << "Year Made: " << motorbike.getYearMade() << endl;
            cout << "Description: " << motorbike.getDescription() << endl;
            cout << "Point Cost: " << motorbike.getPointCost() << endl;
            cout << "Minimum Request Rating: " << motorbike.getMinRequestRating() << endl;
            cout << "Rent Day: " << motorbike.getRentDay() << endl;
            cout << "Location: " << motorbike.getCity() << endl;
            cout << endl;
        }
    }
}

// Member can make a request to rent motorbike
void Member::requestToRent(Database &database)
{
    string choice;
    searchMotorbyCity(database);
    cout << "Enter the owner that you want to rent the motorbike from, or 0 to cancel the request: ";
    getline(cin, choice);

    if (stoi(choice) == 0)
    {
        cout << "Your request has been canceled.\n";
    }
    else
    {
        // Loop through the member list
        for (auto &i : database.getListOfMember())
        {
            // check if the user input is match with Member user name
            if (i.username == choice)
            {
                Request newRequest(username, i.username, request_rating, "Pending");
                database.addRequestToList(newRequest);
            }
        }
    }
}

void Member::checkAndApproveRentRequests(Database &database)
{
    string choice;
    cout << "List of requests" << endl;
    cout << "----------------" << endl;
    for (auto &i : database.getListOfRequest())
    {
        if (i.requestee == username)
        {
            cout << i.requester << endl;
            cout << i.requester_rating << endl;
            cout << '\n';
        }
    }
    cout << "Enter the user you want to approve request of, or 0 to cancel the approval process: ";
    getline(cin, choice);
    if (stoi(choice) == 0)
    {
        cout << "The approval process has been canceled.\n";
    }
    else
    {
        for (auto &i : database.getListOfRequest())
        {
            if (i.requestee == username)
            {
                if (i.requester == choice)
                {
                    database.acceptRequestsFromList(i);
                }
            }
        }
    }
}

string &Member::getUsername()
{
    return username;
}

string &Member::getPassword()
{
    return password;
}

// Admin functions
void Admin::viewAllMembers(Database &database)
{
    for (auto &i : database.getListOfMember())
    {
        i.viewInformation();
    }
}

void Admin::viewAllMotorbikes(Database &database)
{
    for (auto &i : database.getListOfMotorbikeForRent())
    {
        i.viewmotorInfo();
    }
}

string &Admin::getUsername()
{
    return username;
}

string &Admin::getPassword()
{
    return password;
}