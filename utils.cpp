#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "utils.h"
#include "database.h"
#include "users.h"
#include "motorbike.h"
using namespace std;

void Utility::saveDataToFile(Database &database, string &data_type)
{
    if (data_type == "members")
    {
        ofstream member_test("member_test.txt");

        for (size_t i = 0; i < database.listOfMember.size(); i++)
        {
            member_test << database.listOfMember[i].username << ',' << 
            database.listOfMember[i].password << ',' << 
            database.listOfMember[i].fullName << ',' << 
            database.listOfMember[i].phoneNumber << ',' << 
            database.listOfMember[i].idType << ',' << 
            database.listOfMember[i].idPassportNumber << ',' << 
            database.listOfMember[i].driverLicenseNumber << ',' << 
            database.listOfMember[i].expiryDate << ',' <<
            database.listOfMember[i].creditPoints << ',' <<
            database.listOfMember[i].rent_rating << ',' << 
            database.listOfMember[i].request_rating << ',' <<
            int(database.listOfMember[i].hasMotorbike) << '\n';
        }
    }
    else if (data_type == "motorbikes")
    {
        ofstream motorbike_test("motorbike.txt");

        for (size_t i = 0; i < database.listOfMotorbikeForRent.size(); i++)
        {
            motorbike_test << database.listOfMotorbikeForRent[i].owner << ',' << 
            database.listOfMotorbikeForRent[i].model << ',' << 
            database.listOfMotorbikeForRent[i].engineSize << ',' << 
            database.listOfMotorbikeForRent[i].transMode << ',' << 
            database.listOfMotorbikeForRent[i].yearMade << ',' << 
            database.listOfMotorbikeForRent[i].description << ',' << 
            database.listOfMotorbikeForRent[i].pointCost << ',' << 
            database.listOfMotorbikeForRent[i].minRequestRating << ',' << 
            database.listOfMotorbikeForRent[i].rent_day << ',' << 
            database.listOfMotorbikeForRent[i].rent_status << ',' << 
            database.listOfMotorbikeForRent[i].city << '\n';
        }
    }
}

void Utility::loadDataFromFile(Database &database, const string &filename1, const string &filename2)
{
    ifstream members_test(filename1), motorbikes_test(filename2);
    string test;
    Motorbike motorbike;
    Member member;

    if (members_test.is_open())
    {
        while (!members_test.eof())
        {
            string username, password, fullName, phoneNumber, idType, idPassportNumber, 
                   driverLicenseNumber, expiryDate, creditPoints_temp, hasMotorbike_temp;
            int creditPoints;
            bool hasMotorbike;
            getline(members_test, test);

            stringstream teststr(test);
            getline(teststr, username, ',');
            getline(teststr, password, ',');
            getline(teststr, fullName, ',');
            getline(teststr, phoneNumber, ',');
            getline(teststr, idType, ',');
            getline(teststr, idPassportNumber, ',');
            getline(teststr, driverLicenseNumber, ',');
            getline(teststr, expiryDate, ',');
            getline(teststr, creditPoints_temp, ',');
            creditPoints = stoi(creditPoints_temp);
            getline(teststr, hasMotorbike_temp, '\n');
            if (hasMotorbike_temp == "1")
            {
                hasMotorbike = true;
            }
            else hasMotorbike = false;

            Member member(username, password,fullName, phoneNumber, idType, idPassportNumber, driverLicenseNumber, expiryDate, creditPoints, hasMotorbike);
            database.addMemberToList(member);
        }
    }
    else
    {
        cout << "Can't open members.txt. Please check if the file is available.\n";
    }

    if (motorbikes_test.is_open())
    {
        while (!motorbikes_test.eof())
        {
            string username, model, engineSize_temp, transMode, yearMade_temp, description, pointCost_temp,
                   minRentRating_temp, rent_day, rent_status, city;
            int engineSize, yearMade, pointCost, minRenRating;
            getline(motorbikes_test, test);

            stringstream teststr(test);
            getline(teststr, username, ',');
            getline(teststr, model, ',');
            getline(teststr, engineSize_temp, ',');
            engineSize = stoi(engineSize_temp);
            getline(teststr, transMode, ',');
            getline(teststr, yearMade_temp, ',');
            yearMade = stoi(yearMade_temp);
            getline(teststr, description, ',');
            getline(teststr, pointCost_temp, ',');
            pointCost = stoi(pointCost_temp);
            getline(teststr, minRentRating_temp, ',');
            minRenRating = stoi(minRentRating_temp);
            getline(teststr, rent_day, ',');
            getline(teststr, rent_status, ',');
            getline(teststr, city, '\n');

            Motorbike motorbike(username, model, engineSize, 
                      transMode, yearMade, description, pointCost, minRenRating, rent_day, rent_status, city);
            database.addMotorbikeToList(motorbike);
        }
    }
    else
    {
        cout << "Can't open motorbikes.txt. Please check if the file is available.\n";
    }
}