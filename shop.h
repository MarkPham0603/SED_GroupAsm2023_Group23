#ifndef SHOP_H
#define SHOP_H
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

#endif