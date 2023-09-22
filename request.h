#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
#include "utils.h"
#include "database.h"
#include "users.h"
using namespace std;

class Utility;
class Database;
class Member;

class Request
{
private:
    string requester;
    string requestee;
    int requester_rating;
    string status;

public:
    Request(const string &requester = "", const string &requestee = "", const int requester_rating = 0, const string &status = "")
        : requester(requester), requestee(requestee), requester_rating(requester_rating), status(status){};
    friend Utility;
    friend Database;
    friend Member;
};

#endif