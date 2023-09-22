#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
using namespace std;

class Request
{
private:
    string requester;
    string requestee;
    string status;
public:
    Request(const string &requester = "", const string &requestee = "", const string& status= "")
        : requester(requester), requestee(requestee), status(status){};
};

#endif