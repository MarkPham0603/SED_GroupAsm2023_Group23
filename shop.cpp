#include <iostream>
#include <string>
#include <iomanip>
#include "shop.h"
using namespace std;

// Login menu for app
void Shop::loginMenu(Admin &admin, Database &database)
{
    int user_choice = 0;
    bool login_success = false;
    string username, password;

    // users enter their choice
    cout << "============================================================" << endl;
    cout << "Sign in as: " << endl;
    cout << "1. Member" << endl;
    cout << "2. Admin" << endl;
    cout << "3. Guest" << endl;

    while (login_success == false)
    {
        cout << "\nPlease enter your login choice (a number from 1 to 3): ";
        cin >> user_choice;
        cin.sync();
        // Divide user's choice to 3: login as member, admin and guest
        switch (user_choice)
        {
        case 1:
            cout << "============================================================" << endl;
            cout << "Enter your username: ";
            getline(cin, username);
            cout << "Enter your password: ";
            getline(cin, password);
            for (auto &i : database.getListOfMember())
            {
                if (i.getUsername() == username)
                {
                    if (i.getPassword() == password)
                    {
                        cout << "Login successfully as Member. Welcome " << username << "!\n";
                        login_success = true;
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
                }
            }
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

// Welcom screen for the app
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
