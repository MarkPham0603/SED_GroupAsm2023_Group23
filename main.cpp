#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

namespace Member
{
    class Member
    {
    private:
        string username;
        string fullName;
        string phoneNumber;
        string idType;
        string idPassportNumber;
        string driverLicenseNumber;
        string expiryDate;
        int creditPoints;

    public:
        // Member constructor
        Member(const string &username, const string &fullName, const string &phoneNumber,
               const string &idType, const string &idPassportNumber,
               const string &driverLicenseNumber, const string &expiryDate)
            : username(username), fullName(fullName), phoneNumber(phoneNumber),
              idType(idType), idPassportNumber(idPassportNumber),
              driverLicenseNumber(driverLicenseNumber), expiryDate(expiryDate), creditPoints(20)
        {
        }

        // Member view account and personal information
        void viewInformation()
        {
            cout << "Username: " << username << endl;
            cout << "Full Name: " << fullName << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "ID Type: " << idType << endl;
            cout << "ID/Passport Number: " << idPassportNumber << endl;
            cout << "Driver's License Number: " << driverLicenseNumber << endl;
            cout << "Expiry Date: " << expiryDate << endl;
            cout << "Credit Points: " << creditPoints << endl;
        }

        void listMotorbikeForRent()
        {
        }

        void unlistMotorbike()
        {
        }

        void requestToRentMotorbike()
        {
        }

        void rateMotorbike()
        {
        }

        void rateRenter()
        {
        }

        // Static method for member registration
        static Member registerAsMember()
        {
            string username, fullName, phoneNumber, idType, idPassportNumber, driverLicenseNumber, expiryDate;

            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Full Name: ";
            cin.ignore();
            getline(cin, fullName);
            cout << "Enter Phone Number: ";
            cin >> phoneNumber;
            cout << "Enter ID Type: ";
            cin >> idType;
            cout << "Enter ID/Passport Number: ";
            cin >> idPassportNumber;
            cout << "Enter Driver's License Number: ";
            cin >> driverLicenseNumber;
            cout << "Enter Expiry Date: ";
            cin >> expiryDate;

            Member newMember(username, fullName, phoneNumber, idType, idPassportNumber, driverLicenseNumber, expiryDate);
            cout << "Registration successful. Welcome, " << username << "!" << endl;
            return newMember;
        }

        bool login(const string &enteredUsername)
        {
            if (enteredUsername == username)
            {
                cout << "Login successful. Welcome, " << username << "!" << endl;
                return true;
            }
            else
            {
                cout << "Login failed. Invalid username." << endl;
                return false;
            }
        }
    };

    class Admin
    {
    public:
        void viewAllMembers(const vector<Member> &members)
        {
        }
    };
}

namespace Shop
{
    class Shop
    {
    private:
        string name;
        vector<Motorbike::Motorbike> motorbikes;

    public:
        // constructor
        Shop(string name = "") : name(name){};
        // deconstructor
        ~Shop()
        {
            name.clear();
        }
        void appMenu();
        void guestMenu();
        void memberMenu();
        void adminMenu();
        void displayWelcomeScreen();
    };

    void Shop::appMenu(){
        cout << "=========================================================" << endl;
        cout << "WELCOME TO " << name << " MOTORBIKE RENTAL SHOP" << endl;
        cout << "=========================================================" << endl;
    }
}

namespace Motorbike
{
    class Motorbike
    {
    private:
        string names;
        string model;
        int engineSize;
        string transModel;
        int yearMade;
        string description;
        int consumePoint;
        int retailperDay;
        int minrentRating;
        int motorbikeRating;

    public:
    };
};

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