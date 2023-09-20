#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>
#include <fstream>
#include "database.h"
using namespace std;

class Utility
{
public:
    void saveDataToFile(ofstream &ofs, Database &database, string &file_name, string &data_type);
    void loadDataFromFile(string file_name);
    void checkInput(string input);
    void error_handling();
};

#endif