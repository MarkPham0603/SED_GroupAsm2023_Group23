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
        Motorbike::Motorbike motorbike;
        bool hasMotorbike;

    public:
        // Member constructor
        Member(const string &username, const string &fullName, const string &phoneNumber,
               const string &idType, const string &idPassportNumber,
               const string &driverLicenseNumber, const string &expiryDate)
            : username(username), fullName(fullName), phoneNumber(phoneNumber),
              idType(idType), idPassportNumber(idPassportNumber),
              driverLicenseNumber(driverLicenseNumber), expiryDate(expiryDate), creditPoints(20), motorbike(motorbike),hasMotorbike(false)
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
            motorbike.viewmotorInfo();
        }
        
        void listMotorbikeForRent() {
                if (!hasMotorbike) {
                cout << "You don't have a motorbike to list for rent." << endl;
            } else {
                cout << "Your Motorbike for Rent:" << endl;
                motorbike.viewmotorInfo();
            }
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

    void Shop::mainMenu() {
        cout << "============================================================" << endl;
        cout << "EEET2482/COSC2082 GROUP ASSIGNMENT" << endl;
        cout << "MOTORBIKE RENTAL APPLICATION" << endl;
        cout << "\n Instructor: Dr. Ling Huo Chong" << endl;
        cout << "Group: Group 23" << endl;
        cout << "s3970818, Student Name: Trinh Quang Huy" << endl;
        cout << "s3929256, Student Name: Pham Minh Hoa" << endl;
        cout << "s3938309, Student Name: Nguyen Dinh Quoc Bao" << endl;
        cout << "============================================================" << endl;
        cout << "============================================================" << endl;
        cout << "Sign in as: " << endl;
        cout << "1. Member" << endl;
        cout << "2. Admin" << endl;
        cout << "3. Guest" << endl;
        cout << "\nPlease enter your choice: ";
    }

    void Shop::memberMenu() {
        cout << "============================================================" << endl;
        cout << "Enter your username:";
        cout << "Enter your password:";

    }

        void Shop::displayWelcomeScreen() {
        cout << "============================================================" << endl;
        cout << "WELCOME TO " << name << " MOTORBIKE RENTAL SHOP" << endl;
        cout << "============================================================" << endl;
    }
}

namespace Motorbike {
    class Motorbike{
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
        //Motorbike constructor
        Motorbike(const string &name, const string &model, const int &engineSize,
        const string &transModel, const int &yearMade, const string &description,
        const int &consumePoint, const int &retailperDay, const int &minrentRating,
        const int &motorbikeRating, const string &city)
        : name(name), model(model), engineSize(engineSize), transModel(transModel),
        yearMade(yearMade), description(description), consumePoint(consumePoint),
        retailperDay(retailperDay), minrentRating(minrentRating), motorbikeRating(motorbikeRating), city(city){}

        //View motorbike models
        void viewmotorInfo(){
            cout << "Motorbike Name: " << name << endl;
            cout << "Motorbike Model: " << model << endl;
            cout << "Engine Size: " << engineSize << endl;
            cout << "Transmission Model: " << transModel << endl;
            cout << "Production Year: " << yearMade << endl;
            cout << "Description: " << description << endl;
            cout << "Point Cost: " << consumePoint << endl;
            cout << "Rating: " << motorbikeRating << endl;
            cout << "Location: " << city << endl;
        }

        void listforRent(){

        }

        void unlist(){

        }

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