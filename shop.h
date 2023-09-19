#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Shop
{
private:
    string name;

public:
    // constructor
    Shop(string name = "") : name(name){};
    // deconstructor
    ~Shop()
    {
        name.clear();
    }
    void mainMenu();
    void guestMenu();
    void memberMenu();
    void adminMenu();
    void displayWelcomeScreen();
    void viewAllMotorbikeForRent();
    void viewAllMotorbikeForGuest();
};

void Shop::mainMenu()
{
    cout << "============================================================" << endl;
    cout << "EEET2482/COSC2082 GROUP ASSIGNMENT" << endl;
    cout << "MOTORBIKE RENTAL APPLICATION" << endl;
    cout << "\n Instructor: Dr. Ling Huo Chong" << endl;
    cout << "Group: Group 23" << endl;
    cout << "s3970818, Student Name: Trinh Quang Huy" << endl;
    cout << "s3929256, Student Name: Pham Minh Hoa" << endl;
    cout << "s3938309, Student Name: Nguyen Dinh Quoc Bao" << endl;
    cout << "============================================================" << endl;
    cout << "============================================================" << endl;
    cout << "Sign in as: " << endl;
    cout << "1. Member" << endl;
    cout << "2. Admin" << endl;
    cout << "3. Guest" << endl;
    cout << "\nPlease enter your choice: ";
}

void Shop::memberMenu()
{
    cout << "============================================================" << endl;
    cout << "Enter your username:";
    cout << "Enter your password:";
}

void Shop::displayWelcomeScreen()
{
    cout << "============================================================" << endl;
    cout << "WELCOME TO " << name << " MOTORBIKE RENTAL SHOP" << endl;
    cout << "============================================================" << endl;
}

#endif