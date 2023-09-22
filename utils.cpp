#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "utils.h"
#include "database.h"
#include "users.h"
#include "motorbike.h"
#include "request.h"
using namespace std;

// Save all the data to File
void Utility::saveDataToFile(Database &database, string &data_type, const string &filename1, const string &filename2, const string &filename3)
{
    ofstream member_test(filename1), motorbike_test(filename2), requests_test(filename3);

    // Save the data from Member list
    if (member_test.is_open())
    {
        // Loop through the list, save the data, separate each with comma
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
    
    // Save the data from Motor list
    if (motorbike_test.is_open())
    {
        for (size_t i = 0; i < database.listOfMember.size(); i++)
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
    
    // Save the data from Request list
    if (requests_test.is_open())
    {
        for (size_t i = 0; i < database.listOfRequests.size(); i++)
        {
            requests_test << database.listOfRequests[i].requester << ',' <<
            database.listOfRequests[i].requestee << ',' <<
            database.listOfRequests[i].status<< '\n';
        }
    }

    member_test.close();
    motorbike_test.close();
    requests_test.close();
}

// Load the data from file
void Utility::loadDataFromFile(Database &database, const string &filename1, const string &filename2, const string& filename3)
{
    ifstream members_test(filename1), motorbikes_test(filename2), requests_test(filename3);
    string test;
    Motorbike motorbike;
    Member member;

    if (members_test.is_open())
    {
        while (!members_test.eof())
        {
            string username, password, fullName, phoneNumber, idType, idPassportNumber,
                driverLicenseNumber, expiryDate, creditPoints_temp, rent_rating_temp, request_rating_temp, hasMotorbike_temp;
            int creditPoints, rent_rating, request_rating;
            bool hasMotorbike;
            getline(members_test, test);

            // Get data from the file
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
            getline(teststr, rent_rating_temp, ',');
            creditPoints = stoi(rent_rating_temp);
            getline(teststr, request_rating_temp, ',');
            creditPoints = stoi(request_rating_temp);
            getline(teststr, hasMotorbike_temp, '\n');
            if (hasMotorbike_temp == "1")
            {
                hasMotorbike = true;
            }
            else
                hasMotorbike = false;

            // Create new object and add to list
            Member member(username, password, fullName, phoneNumber, idType, idPassportNumber, driverLicenseNumber, expiryDate, creditPoints, rent_rating, request_rating, hasMotorbike);
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
                minRequestRating_temp, rent_day, rent_status, city;
            int engineSize, yearMade, pointCost, minRenRating;
            getline(motorbikes_test, test);

            // Get data from the file
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
            getline(teststr, minRequestRating_temp, ',');
            minRenRating = stoi(minRequestRating_temp);
            getline(teststr, rent_day, ',');
            getline(teststr, rent_status, ',');
            getline(teststr, city, '\n');

            // Create new object and add to list
            Motorbike motorbike(username, model, engineSize,
                                transMode, yearMade, description, pointCost, minRenRating, rent_day, rent_status, city);
            database.addMotorbikeToList(motorbike);
        }
    }
    else
    {
        cout << "Can't open motorbikes.txt. Please check if the file is available.\n";
    }

    if (requests_test.is_open())
    {
        while (!requests_test.eof())
        {
            string requester, requestee, status;
            getline(requests_test, test);

            // Get data from the file
            stringstream teststr(test);
            getline(teststr, requester, ',');
            getline(teststr, requestee, ',');
            getline(teststr, status, ',');

            // Create new object and add to list
            Request request(requester, requestee, status);
            database.addMotorbikeToList(motorbike);
        }
    }
    else
    {
        cout << "Can't open requests.txt. Please check if the file is available.\n";
    }
}