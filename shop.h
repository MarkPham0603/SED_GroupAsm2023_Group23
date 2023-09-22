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
    void startScreen(Database &database);
    void loginMenu(Database &database); 
};

#endif