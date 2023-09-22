#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include <iostream>
#include <string>
#include "utils.h"
using namespace std;

class Utility;

class Motorbike
{
private:
    string username;
    string model;
    int engineSize;
    string transMode;
    int yearMade;
    string description;
    int pointCost;
    int minrentRating;
    string rent_day;
    string rent_status;
    string city;

public:
    // Motorbike constructor
    Motorbike(const string username = "", const string &model = "", const int engineSize = 0,
              const string &transMode = "", const int yearMade = 0, const string &description = "",
              const int pointCost = 0, const int minrentRating = 0,
              const string &rent_day = "", const string &rent_status = "", const string &city = "")
        : username(username), model(model), engineSize(engineSize), transMode(transMode),
          yearMade(yearMade), description(description), pointCost(pointCost),
          minrentRating(minrentRating), rent_day(rent_day), rent_status(rent_status), city(city){};

    // View motorbike models
    void viewmotorInfo();
    // Get owner's username
    string& getUsername();

    friend Utility;
};

#endif