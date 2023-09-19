#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME
#include <iostream>
#include <string>
using namespace std;

namespace utility_class
{
    class utility
    {
    public:
        void saveDataToFile(string file_name);
        void loadDataFromFile(string file_name);
        void checkInput(string input);
        void error_handling();
    };
}

#endif