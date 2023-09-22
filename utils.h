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
class Request;

class Utility
{
public:
    void saveDataToFile(Database &database, const string &filename1, const string &filename2, const string &filename3);
    void loadDataFromFile(Database &database, const string &filename1, const string &filename2, const string &filename3);
};

#endif