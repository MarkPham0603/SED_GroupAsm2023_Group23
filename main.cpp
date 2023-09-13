#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

namespace Shop
{
    class Shop
    {
    private:
        string name;

    public:
        // constructor
        Shop(string name = "") : name(name){};
        // deconstructor
        ~Shop()
        {
            name.clear();
        }
        void mainMenu();
        void guestMenu();
        void memberMenu();
        void adminMenu();
        void displayWelcomeScreen();
    };

}

namespace utility
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

int main()
{

    return 0;
}