#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include <iostream>
#include <string>
using namespace std;

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
    string startTime;
    string endTime;
    string city;

public:
    // Motorbike constructor
    Motorbike(const string username = "", const string &model = "", const int engineSize = 0,
              const string &transMode = "", const int yearMade = 0, const string &description = "",
              const int pointCost = 0, const int minrentRating = 0,
              const string &startTime = "", const string &endTime = "", const string &city = "")
        : username(username), model(model), engineSize(engineSize), transMode(transMode),
          yearMade(yearMade), description(description), pointCost(pointCost),
          minrentRating(minrentRating), startTime(startTime), endTime(endTime), city(city){};

    // View motorbike models
    void viewmotorInfo();
    // Get owner's username
    string& getUsername();

    friend Utility;
};

#endif