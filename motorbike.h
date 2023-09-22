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
    string owner;
    string model;
    int engineSize;
    string transMode;
    int yearMade;
    string description;
    int pointCost;
    int minRequestRating;
    string rent_day;
    string rent_status;
    string city;

public:
    // Motorbike constructor
    Motorbike(const string owner = "", const string &model = "", const int engineSize = 0,
              const string &transMode = "", const int yearMade = 0, const string &description = "",
              const int pointCost = 0, const int minRequestRating = 0,
              const string &rent_day = "", const string &rent_status = "", const string &city = "")
        : owner(owner), model(model), engineSize(engineSize), transMode(transMode),
          yearMade(yearMade), description(description), pointCost(pointCost),
          minRequestRating(minRequestRating), rent_day(rent_day), rent_status(rent_status), city(city){};

    // View motorbike models
    void viewmotorInfo();
    // Get owner's username
    string& getOwner();
    // Getter for model
    string& getModel();
    // Getter for engineSize
    int& getEngineSize();
    // Getter for transMode
    string& getTransMode();
    // Getter for yearMade
    int& getYearMade();
    // Getter for description
    string& getDescription();
    // Getter for pointCost
    int& getPointCost();
    // Getter for minrentRating
    int& getMinRequestRating();
    // Getter for rent_day
    string& getRentDay();
    // Getter for rent_status
    string& getRentStatus();
    // Getter for city
    string& getCity();

    friend Utility;
};

#endif