#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"
#include "database.h"
using namespace std;

void Utility::saveDataToFile(ofstream &ofs, Database &database, string &data_type)
{
    if (data_type == "members")
    {
        for (size_t i = 0; i < database.listOfMember.capacity(); i++)
        {
            ofs << database.listOfMember[i].username << ',' << 
            database.listOfMember[i].password << ',' << 
            database.listOfMember[i].fullName << ',' << 
            database.listOfMember[i].phoneNumber << ',' << 
            database.listOfMember[i].idType << ',' << 
            database.listOfMember[i].idPassportNumber << ',' << 
            database.listOfMember[i].driverLicenseNumber << ',' << 
            database.listOfMember[i].expiryDate << ',' << 
            database.listOfMember[i].creditPoints << '\n';
        }
    }
    else if (data_type == "motorbikes")
    {
        for (size_t i = 0; i < database.listOfMotorbikeForRent.capacity(); i++)
        {
            ofs << database.listOfMotorbikeForRent[i].username << ',' << 
            database.listOfMotorbikeForRent[i].model << ',' << 
            database.listOfMotorbikeForRent[i].engineSize << ',' << 
            database.listOfMotorbikeForRent[i].transMode << ',' << 
            database.listOfMotorbikeForRent[i].yearMade << ',' << 
            database.listOfMotorbikeForRent[i].description << ',' << 
            database.listOfMotorbikeForRent[i].pointCost << ',' << 
            database.listOfMotorbikeForRent[i].minrentRating << ',' << 
            database.listOfMotorbikeForRent[i].startTime << ',' << 
            database.listOfMotorbikeForRent[i].endTime << ',' << 
            database.listOfMotorbikeForRent[i].city << '\n';
        }
    }
}