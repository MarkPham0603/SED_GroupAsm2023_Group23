#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

namespace Member
{
    class Guest
    {
        string fullName;
        string phoneNumber;
        string idType;
        string idPassportNumber;
        string driverLicenseNumber;
        string expiryDate;

    public:
        // Guest class constructor
        Guest(const string &fullName, const string &phoneNumber,
              const string &idType, const string &idPassportNumber,
              const string &driverLicenseNumber, const string &expiryDate)
            : fullName(fullName), phoneNumber(phoneNumber),
              idType(idType), idPassportNumber(idPassportNumber),
              driverLicenseNumber(driverLicenseNumber), expiryDate(expiryDate){};

        Member registerAsMember()
        {
            string username;

            cout << "Enter Username: ";
            cin >> username;

            Member newMember(username, fullName, phoneNumber, idType, idPassportNumber, driverLicenseNumber, expiryDate);
            cout << "Registration successful. Welcome, " << username << "!" << endl;
            return newMember;
        }

        void viewAllMotorbikeForRent(Shop::Shop shop){
            shop.viewAllMotorbikeForRent();
        }

        friend Member;
    };

    class Member : public Guest
    {
    private:
        string username;
        int creditPoints;
        Motorbike::Motorbike motorbike;
        bool hasMotorbike;

    public:
        // Member constructor
        Member(const string &fullName, const string &phoneNumber,
               const string &idType, const string &idPassportNumber,
               const string &driverLicenseNumber, const string &expiryDate,
               const string &username, int creditPoints = 20)
            : Guest(fullName, phoneNumber, idType, idPassportNumber, driverLicenseNumber, expiryDate),
              username(username), creditPoints(20), motorbike(motorbike), hasMotorbike(false){};
    
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
            if (!hasMotorbike) {
                cout << "You don't have a motorbike listed for rent." << endl;
            } else {
                cout << "Unlisting your Motorbike for Rent:" << endl;
                motorbike.viewmotorInfo(); // Display the details of the motorbike being unlisted
                hasMotorbike = false; // Mark that the member no longer has a listed motorbike
                cout << "Your motorbike has been unlisted." << endl;
            }
        }   
    };
    /*class Member
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

        // Show the motor list of the user
        void listMotorbikeForRent() {
                if (!hasMotorbike) {
                cout << "You don't have a motorbike to list for rent." << endl;
            } else {
                cout << "Your Motorbike for Rent:" << endl;
                motorbike.viewmotorInfo();
            }
        }

        // Hide the motor list of the user
        void unlistMotorbike()
        {
            if (!hasMotorbike) {
                cout << "You don't have a motorbike listed for rent." << endl;
            } else {
                cout << "Unlisting your Motorbike for Rent:" << endl;
                motorbike.viewmotorInfo(); // Display the details of the motorbike being unlisted
                hasMotorbike = false; // Mark that the member no longer has a listed motorbike
                cout << "Your motorbike has been unlisted." << endl;
            }
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

    class Admin {
    private:
        string username;
        string password;

    public:
        Admin(const string& adminUsername, const string& adminPassword)
            : username(adminUsername), password(adminPassword) {}

        bool loginAsAdmin(const string& enteredUsername, const string& enteredPassword) {
            if (enteredUsername == username && enteredPassword == password) {
                cout << "Admin login successful. Welcome, " << username << "!" << endl;
                return true;
            } else {
                cout << "Admin login failed. Invalid username or password." << endl;
                return false;
            }
        }
    };
    */
}

namespace Shop
{
    class Shop
    {
    private:
        string name;
        vector<Motorbike::Motorbike> listOfMotorbikeForRent;
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
        void viewAllMotorbikeForRent();
    };

    void Shop::mainMenu()
    {
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

    void Shop::memberMenu()
    {
        cout << "============================================================" << endl;
        cout << "Enter your username:";
        cout << "Enter your password:";
    }

    void Shop::displayWelcomeScreen()
    {
        cout << "============================================================" << endl;
        cout << "WELCOME TO " << name << " MOTORBIKE RENTAL SHOP" << endl;
        cout << "============================================================" << endl;
    }
}

namespace Motorbike
{
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
        void viewmotorInfo()
        {
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