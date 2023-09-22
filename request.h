#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
#include "utils.h"
#include "database.h"
using namespace std;

class Utility;
class Database;

class Request
{
private:
    string requester;
    string requestee;
    string status;

public:
    Request(const string &requester = "", const string &requestee = "", const string &status = "")
        : requester(requester), requestee(requestee), status(status){};
    friend Utility;
    friend Database;
};

#endif