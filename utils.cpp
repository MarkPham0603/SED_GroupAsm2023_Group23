#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"
#include "database.h"
using namespace std;

void Utility::saveDataToFile(ofstream &ofs, Database &database, string &file_name, string &data_type)
{
    ofs.open(file_name, ios::app);
    if (data_type == "members")
    {
        for (size_t i = 0; i < database.listOfMember.capacity(); i++)
        {
            ofs << database.listOfMember[i].username << "," << 
            database.listOfMember[i].password << "," << 
            database.listOfMember[i].fullName << "," << 
            database.listOfMember[i].phoneNumber << "," << 
            database.listOfMember[i].idType << "," << 
            database.listOfMember[i].idPassportNumber << "," << 
            database.listOfMember[i].driverLicenseNumber << "," << 
            database.listOfMember[i].expiryDate,
            database.listOfMember[i].creditPoints;
        }
    }
    
}