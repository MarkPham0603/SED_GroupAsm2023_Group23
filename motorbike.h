#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include <iostream>
#include <string>
using namespace std;

class Motorbike
{
private:
    string name;
    string model;
    int engineSize;
    string transModel;
    int yearMade;
    string description;
    int pointCost;
    int retailperDay;
    int minrentRating;
    int motorbikeRating;
    string city;

public:
    // Motorbike constructor
    Motorbike(const string &name, const string &model, const int engineSize,
              const string &transModel, const int yearMade, const string &description,
              const int pointCost, const int retailperDay, const int minrentRating,
              const int motorbikeRating, const string &city)
        : name(name), model(model), engineSize(engineSize), transModel(transModel),
          yearMade(yearMade), description(description), pointCost(pointCost),
          retailperDay(retailperDay), minrentRating(minrentRating), motorbikeRating(motorbikeRating), city(city){};

    // Default Motorbike constructor
    Motorbike() : name(""), model(""), engineSize(0), transModel(""), yearMade(0),
                  description(""), pointCost(0), retailperDay(0), minrentRating(0), motorbikeRating(0), city(""){};

    // View motorbike models
    void viewmotorInfo();
};

#endif