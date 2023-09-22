#include <iostream>
#include <string>
#include <iomanip>
#include "shop.h"
using namespace std;

// Login menu for app
void Shop::loginMenu(Admin &admin, Database &database)
{
    int user_choice = 0;
    bool login_success = false, exit_program = false;
    string username, password;

    while (exit_program == false)
    {
        login_success = false;

        cout << "============================================================" << endl;
        cout << "Sign in as: " << endl;
        cout << "1. Member" << endl;
        cout << "2. Admin" << endl;
        cout << "3. Guest" << endl;
        cout << "0. Exit program" << endl;
        cout << "\nPlease enter your login choice (a number from 0 to 3): ";

        while (login_success == false)
        {
            // users enter their choice
            cin >> user_choice;
            cin.sync();
            // Divide user's choice to 3: login as member, admin and guest
            switch (user_choice)
            {
            case 0:
                cout << "============================================================" << endl;
                cout << "Exiting the program. See you later.\n";
                cout << "============================================================" << endl;
                login_success = true;
                exit_program = true;
                break;
            case 1:
                cout << "============================================================" << endl;
                cout << "Enter your username: ";
                getline(cin, username);
                cout << "Enter your password: ";
                getline(cin, password);
                for (auto &member : database.getListOfMember())
                {
                    if (member.getUsername() == username)
                    {
                        if (member.getPassword() == password)
                        {
                            cout << "Login successfully as Member. Welcome " << username << "!\n";
                            login_success = true;
                            memberMenu(member, database);
                        }
                    }
                }
                break;
            case 2:
                cout << "============================================================" << endl;
                cout << "Enter your username: ";
                getline(cin, username);
                cout << "Enter your password: ";
                getline(cin, password);
                if (admin.getUsername() == username)
                {
                    if (admin.getPassword() == password)
                    {
                        cout << "Login successfully as Administrator.\n";
                        login_success = true;
                        adminMenu(admin, database);
                    }
                }
                break;
            case 3:
                cout << "Login successfully as Guest.";
                Guest guest;
                login_success = true;
                guestMenu(guest, database);
                break;
            default:
                cout << "============================================================" << endl;
                cout << "Invalid choice! Please enter your choice again (a number from 1 to 3): ";
                break;
            };
        }
    }
}

void Shop::memberMenu(Member &member, Database &database)
{
    int choice = 1;

    while (choice != 0)
    {
        cout << "============================================================" << endl;
        cout << "1. View personal information" << endl;
        cout << "2. List a motorbike for rent" << endl;
        cout << "3. Unlist your motorbike" << endl;
        cout << "4. Search a motorbike by city" << endl;
        cout << "5. Request a motorbike" << endl;
        cout << "6. Check and approve requests to rent your motorbike" << endl;
        cout << "0. Log out" << endl;
        cout << "============================================================" << endl;
        cout << "Enter a choice (a number from 0 to 6): ";
        cin >> choice;
        cin.sync();
        switch (choice)
        {
        case 0:
            cout << "Log out successfullly.\n";
            break;
        case 1:
            member.viewInformation();
        case 2:
            member.listMotorbikeForRent(database);
        case 3:
            member.unlistMotorbike(database);
        case 4:
            member.searchMotorbyCity(database);
        case 5:
            member.requestToRent(database);
        case 6:
            member.checkAndApproveRentRequests(database);
        default:
            cout << "Invalid choice! Please try again!";
            break;
        }
    }
}

void Shop::guestMenu(Guest &guest, Database &database)
{
    int guest_choice = 1;
    while (guest_choice != 0)
    {
        cout << "============================================================" << endl;
        cout << "1. Register as Member" << endl;
        cout << "2. View Motorbikes" << endl;
        cout << "0. Log out" << endl;
        cout << "============================================================" << endl;
        cout << "\n Please enter the available options from 0 to 2: ";
        cin >> guest_choice;
        cin.sync();
        switch (guest_choice)
        {
        case 0:
            cout << "Log out successfully!\n";
            break;
        case 1:
            guest.registerAsMember(database);
            break;
        case 2:
            guest.viewAllMotorbikeForGuest(database);
            break;
        default:
            cout << "Invalid input, please try again!";
            break;
        };
    }
}

void Shop::adminMenu(Admin &admin, Database &database)
{
    int choice = 1;
    while (choice != 0)
    {
        cout << "============================================================" << endl;
        cout << "1. View all members information" << endl;
        cout << "2. View all motorbikes information" << endl;
        cout << "0. Log out" << endl;
        cout << "============================================================" << endl;
        cout << "\n Please enter the available options from 0 to 2: ";
        cin >> choice;
        cin.sync();
    }
    
}

// Welcome screen for the app
void Shop::startScreen(Admin &admin, Database &database)
{
    cout << "============================================================" << endl;
    cout << "EEET2482/COSC2082 GROUP ASSIGNMENT" << endl;
    cout << "MOTORBIKE RENTAL APPLICATION" << endl;
    cout << "\nInstructor: Dr. Ling Huo Chong" << endl;
    cout << "Group: Group 23" << endl;
    cout << "s3970818, Student Name: Trinh Quang Huy" << endl;
    cout << "s3929256, Student Name: Pham Minh Hoa" << endl;
    cout << "s3938309, Student Name: Nguyen Dinh Quoc Bao" << endl;
    cout << "============================================================" << endl;
    loginMenu(admin, database);
}
