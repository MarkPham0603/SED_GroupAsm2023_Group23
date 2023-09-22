#include <iostream>
#include <string>
#include <iomanip>
#include "shop.h"
using namespace std;

void Shop::loginMenu(Database &database)
{
    int user_choice = 0;
    bool login_success = false;
    string username, password;

    cout << "============================================================" << endl;
    cout << "Sign in as: " << endl;
    cout << "1. Member" << endl;
    cout << "2. Admin" << endl;
    cout << "3. Guest" << endl;
    cout << "\nPlease enter your choice: ";

    while (login_success == false)
    {
        cin >> user_choice;
        cin.sync();
        switch (user_choice)
        {
        case 1:
            cout << "============================================================" << endl;
            cout << "Enter your username: ";
            getline(cin, username);
            cout << "Enter your password: ";
            getline(cin, password);    
            break;
        case 2:
            cout << "============================================================" << endl;
            cout << "Enter your username: ";
            getline(cin, username);
            cout << "Enter your password: ";
            getline(cin, password);
            break;
        case 3:
            cout << "Login successfully as Guest.";
            break;
        default:
            cout << "============================================================" << endl;
            cout << "Invalid choice! Please enter your choice again (a number from 1 to 3): ";
            break;
        };
    }
}

void Shop::startScreen(Database &database)
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
    loginMenu(database);
}

