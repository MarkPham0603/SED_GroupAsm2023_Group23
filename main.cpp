#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "database.h"
#include "motorbike.h"
#include "shop.h"
#include "users.h"
#include "utils.h"
using namespace std;

int main()
{
    Database database;
    Utility utils;
    const string filename1 = "./lists/members.txt", filename2 = "./lists/motorbikes.txt", filename3 = "./lists/requests.txt";
    utils.loadDataFromFile(database, filename1, filename2, filename3);
    return 0;
}