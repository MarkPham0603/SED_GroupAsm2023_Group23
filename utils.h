#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>
#include <fstream>
#include "database.h"
#include "users.h"
#include "motorbike.h"
using namespace std;

class Database;
class Member;
class Motorbike; 

class Utility
{
public:
    void saveDataToFile(Database &database, string &data_type);
    void loadDataFromFile(Database &database, const string &file_name1, const string &filename2);
};

#endif