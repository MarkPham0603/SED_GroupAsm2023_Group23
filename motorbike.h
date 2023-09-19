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
    int consumePoint;
    int retailperDay;
    int minrentRating;
    int motorbikeRating;
    string city;

public:
    // Motorbike constructor
    Motorbike(const string &name, const string &model, const int &engineSize,
              const string &transModel, const int &yearMade, const string &description,
              const int &consumePoint, const int &retailperDay, const int &minrentRating,
              const int &motorbikeRating, const string &city)
        : name(name), model(model), engineSize(engineSize), transModel(transModel),
          yearMade(yearMade), description(description), consumePoint(consumePoint),
          retailperDay(retailperDay), minrentRating(minrentRating), motorbikeRating(motorbikeRating), city(city) {}

    // View motorbike models
    void viewmotorInfo();
};

#endif