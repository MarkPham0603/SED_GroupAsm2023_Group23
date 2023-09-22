#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <string>
#include <iomanip>
#include "database.h"
using namespace std;

class Database;

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
    void startScreen(Admin &admin, Database &database);
    void loginMenu(Admin &admin, Database &database);
    void memberMenu(Member &member, Database &database);
    void adminMenu(Admin &admin, Database &database);
    void guestMenu(Guest &guest, Database &database);
};

#endif