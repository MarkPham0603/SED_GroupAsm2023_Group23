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
        Guest(string fullName = "", string phoneNumber = "",
              string idType = "", string idPassportNumber = "",
              string driverLicenseNumber = "", string expiryDate = "")
            : fullName(fullName), phoneNumber(phoneNumber),
              idType(idType), idPassportNumber(idPassportNumber),
              driverLicenseNumber(driverLicenseNumber), expiryDate(expiryDate){};

        // User enter some personal information for register as Member
        void registerAsMember(Admin admin)
        {
            string username;

            // User input
            cout << "Set your username: ";
            getline(cin, username);
            cout << "Enter full name: ";
            getline(cin, fullName);
            cout << "Enter phone number: ";
            getline(cin, phoneNumber);
            cout << "Enter type of id: ";
            getline(cin, idType);
            cout << "Enter id number: ";
            getline(cin, idPassportNumber);
            cout << "Enter driver license number: ";
            getline(cin, driverLicenseNumber);
            cout << "Enter expiry date for driver license: ";
            getline(cin, expiryDate);

            // Create a new Member object that contain the user input
            Member newMember(username, fullName, phoneNumber, idType, idPassportNumber, driverLicenseNumber, expiryDate);
            admin.addMemberToList(newMember);
            cout << "Registration successful. Welcome, " << username << "!" << endl;
        }

        void viewAllMotorbikeForGuest(Admin admin)
        {
            admin.viewAllMotorbikeForGuest();
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

        void listMotorbikeForRent()
        {
            if (!hasMotorbike)
            {
                cout << "You don't have a motorbike to list for rent." << endl;
            }
            else
            {
                cout << "Your Motorbike for Rent:" << endl;
                motorbike.viewmotorInfo();
            }
        }

        void unlistMotorbike()
        {
            if (!hasMotorbike)
            {
                cout << "You don't have a motorbike listed for rent." << endl;
            }
            else
            {
                cout << "Unlisting your Motorbike for Rent:" << endl;
                motorbike.viewmotorInfo(); // Display the details of the motorbike being unlisted
                hasMotorbike = false;      // Mark that the member no longer has a listed motorbike
                cout << "Your motorbike has been unlisted." << endl;
            }
        }
    };

    class Admin
    {
    private:
        string username;
        string password;
        vector<Member> listOfMember;
        vector<Motorbike::Motorbike> listOfMotorbikeForRent;

    public:
        Admin(const string adminUsername, string adminPassword)
            : username(adminUsername), password(adminPassword){};

        void addMemberToList(Member &new_member)
        {
            listOfMember.push_back(new_member);
        }
        void addMotorbikeToList(Motorbike::Motorbike &new_motorbike)
        {
            listOfMotorbikeForRent.push_back(new_motorbike);
        }

        void viewAllMotorbikeForGuest()
        {
            if (listOfMotorbikeForRent.empty())
            {
                cout << "No motorbikes are available for rent at this time.\n";
            }
            else
            {
                for (size_t i = 0; i < listOfMotorbikeForRent.capacity(); i++)
                {
                    listOfMotorbikeForRent[i].viewmotorInfo();
                }
            }
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
        void viewAllMotorbikeForRent();
        void viewAllMotorbikeForGuest();
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