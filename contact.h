//
// Created by Omran Suleiman on 2023-02-08.
//

#ifndef CPPPROJECT_CONTACT_H
#define CPPPROJECT_CONTACT_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <iomanip>

using namespace std;

class contact {
private:
    string fName;
    string lName;
    string phoneNumber;
    string Birthday;
    string Address;
    string ZipNumber;
    string Email;

public:
    contact() {
        fName = "";
        lName = "";
        phoneNumber = "";
        Birthday = "";
        Address = "";
        ZipNumber = "";
        Email = "";
    }

    contact(string fName, string lName, string phoneNumber, string Birthday, string Address, string ZipNumber,
            string Email) {
        this->fName = fName;
        this->lName = lName;
        this->phoneNumber = phoneNumber;
        this->Birthday = Birthday;
        this->Address = Address;
        this->ZipNumber = ZipNumber;
        this->Email = Email;
    }

    string getfName() const {
        return fName;
    }

    string getlName() const {
        return lName;
    }

    string getphoneNumber() const {
        return phoneNumber;
    }

    string getBirthday() const {
        return Birthday;
    }

    string getAddress() const {
        return Address;
    }

    string getZipNumber() const {
        return ZipNumber;
    }

    string getEmail() const {
        return Email;
    }

    void setfName(string fName) {
        this->fName = fName;
    }

    void setlName(string lName) {
        this->lName = lName;
    }

    void setphoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }

    void setBirthday(string Birthday) {
        this->Birthday = Birthday;
    }

    void setAddress(string Address) {
        this->Address = Address;
    }

    void setZipNumber(string ZipNumber) {
        this->ZipNumber = ZipNumber;
    }

    void
    setEmail(string Email)
    {
        this->Email = Email;
    }

    void CreateContact() {
        char op;

        do {

            while (true) {

                cout << "\n"
                     << setw(106) << " ENTER THE FIRST NAME: ";
                getline(cin, fName);

                if (fName.empty()) {
                    continue;
                }

                if (fName.find_first_not_of("qwertyuiopåäölkjhgfdsazxcvbnmQWERTYUIOPÅÄÖLKJHGFDSAZXCVBNM") ==
                    string::npos) {
                    break;
                } else {
                    cout << "\n"
                         << setw(122) << "ALLOWED CHARACTERS ARE ONLY LETTERS: \n";
                }
            }

            while (true) {
                cout << "\n"
                     << setw(105) << "ENTER THE LAST NAME: ";
                getline(cin, lName);

                if (lName.empty()) {
                    continue;
                }

                if (lName.find_first_not_of("qwertyuiopåäölkjhgfdsazxcvbnmQWERTYUIOPÅÄÖLKJHGFDSAZXCVBNM") ==
                    string::npos) {
                    break;
                } else {
                    cout << "\n"
                         << setw(122) << "ALLOWED CHARACTERS ARE ONLY LETTERS: \n";
                }
            }

            // string phoneNumber;
            cout << "\n"
                 << setw(105) << " ENTER THE PHONE NUMBER:  ";
            bool validTelefonNumbers = false, charDetected = false;
            while (!validTelefonNumbers) {
                getline(cin, phoneNumber);
                if (phoneNumber.length() != 10) {

                    cout << "\n\t\t\t\t\t\t\t\t THE PHONE NUMBERS MUSTE CONSISST OF 10 DIGITS: " << endl;
                    cout << "\t\t\t\t\t\t\t\t ENTER THE PHONE NUMBER:  ";
                    charDetected = false;
                    continue;
                }

                for (int i = 0; i < phoneNumber.length(); i++)
                {
                    if (phoneNumber[i] > '9' || phoneNumber[i] < '0')
                    {
                        cout << "\n\t\t\t\t\t\t\t\t ALLOWED CHARACTERS ARE ONLY NUMBERS: " << endl;
                        cout << "\t\t\t\t\t\t\t\t ENTER THE PHONE NUMBER:  ";
                        charDetected = true;
                        break;
                    }
                }
                if (!charDetected)
                {
                    validTelefonNumbers = true;
                    break;
                }
            }



            cout << "\n"
                 << setw(122) << " ENTER THE BIRTHDAY (ÅÅÅÅ-MM-DD):  ";
            bool validBirthdayNumber = false, CDetected = false;
            while (!validBirthdayNumber) {
                getline(cin, Birthday);

                if (Birthday.length() == 10 && Birthday[4] == '-' && Birthday[7] == '-' && isdigit(Birthday[0]) &&
                    isdigit(Birthday[1]) && isdigit(Birthday[2]) && isdigit(Birthday[3]) && isdigit(Birthday[5]) &&
                    isdigit(Birthday[6]) && isdigit(Birthday[8]) && isdigit(Birthday[9])) {

                    validBirthdayNumber = true;
                } else {
                    cout << "\n"
                         << setw(122) << " BIRTHDAY MUST BE IN SPECIFIED FORMAT: " << endl;
                    cout << "\n"
                         << setw(122) << " ENTER THE BIRTHDAY (ÅÅÅÅ-MM-DD): ";
                }
            }

            bool StreetIsValid = false;
            while (!StreetIsValid) {

                cout << "\n"
                     << setw(120) << " ENTER THE STREET AND HOUSE NUMBER:  ";
                getline(cin, Address);

                if (Address.find_first_not_of("qwertyuiopåäölkjhgfdsazxcvbnmQWERTYUIOPÅÄÖLKJHGFDSAZXCVBNM") !=
                    string::npos & Address.find_first_not_of("0987654321") != string::npos) {
                    StreetIsValid = true;
                } else {
                    cout << "\n"
                         << setw(162)
                         << " THE STREET AND HOUSE NUMBER MUST CINSIST ONLY OF ALPHABETS, SPACE AND DIGITS: ";
                }
            }

            cout << "\n"
                 << setw(107) << " ENTER THE ZIP NUMBER:  ";
            bool validPostNumber = false, charDetectede = false;
            while (!validPostNumber) {
                string word;
                getline(cin, ZipNumber);

                if (ZipNumber.length() != 5) {
                    cout << "\n"
                         << setw(126) << " THE ZIP NUMBER MUST CONSIST OF 5 DIGITIS: " << endl;
                    cout << "\n"
                         << setw(107) << " ENTER THE ZIP NUMBER:  ";
                    charDetectede = false;
                    continue;
                }

                for (int i = 0; i < ZipNumber.length(); i++) {
                    if (ZipNumber[i] > '9' || ZipNumber[i] < '0') {
                        cout << setw(121) << " ALLOWED CHARACTERS ARE ONLY NUMBERS: " << endl;
                        cout << "\n"
                             << setw(107) << " ENTER THE ZIP NUMBER:  ";
                        charDetectede = true;
                        break;
                    }
                }
                if (!charDetectede) {
                    validPostNumber = true;
                }
            }

            bool correctEmail = false;
            while (!correctEmail) {
                cout << "\n"
                     << setw(108) << " ENTER THE EMIL-ADDRESS: ";
                getline(cin, Email);

                if (Email.find("@outlook.com") != string::npos || Email.find(".com") != string::npos ||
                    Email.find(".miun.se") != string::npos || Email.find(".se") != string::npos ||
                    Email.find("@outlook.com") != string::npos || Email.find("@yahoo.com") != string::npos ||
                    Email.find("@gmail.com") != string::npos || Email.find("@hotmail.com") != string::npos) {

                    correctEmail = true;
                } else {
                    cout << "\n"
                         << setw(172)
                         << " THE EMAIL YOU ENTERED IS NOT CORRECT. PLEASE! USE CORRECT DOMAIN. EXAMPLE '@gmail.com' \n";
                }
            }

            while (true) {
                cout << "\n"
                     << setw(140) << "=-------------------------------------------------------------------=" << endl;
                cout << "\n"
                     << setw(140) << "=-------------------------------------------------------------------=" << endl;
                cout << setw(135) << " CONTINUE TO CREAT MORE CONTACT: |y| SAVE THE CONTACT: n| ";
                cin >> op;
                cin.ignore();

                if (op == 'Y' || op == 'y') {

                    break;
                } else if (op == 'N' || op == 'n') {

                    break;
                } else {
                    cout << "\n"
                         << setw(105) << " CHOOSE ONE OF THE OPTIONS: ";
                }
            }
        } while (op == 'Y' || op == 'y');

        cout << "\n\n\n"
             << setw(140) << "=-------------------------------------------------------------------=" << endl;
        cout << "\n"
             << setw(140) << "=-------------------------------------------------------------------=" << endl;
        cout << setw(124) << " CONTACT HAS BEEN CREATED SUCCESSFULLY...";
    }

    // Detta func används för display ovanstående
    void showContact() {
        setlocale(LC_ALL, "sv_se");

        cout << setw(105) << "Name: " << fName << " " << lName << endl;
        cout << setw(105) << "Phone number: " << phoneNumber << endl;
        cout << setw(105) << "Birthday: " << Birthday << endl;
        cout << setw(105) << "Post-Address: " << Address << endl;
        cout << setw(105) << "Post-Number " << ZipNumber << endl;
        cout << setw(105) << "Emil Address: " << Email << endl;
    }
};


void readAllContacts(vector<contact> &contacts);

void searchContact(vector<contact> &contacts);

void deleteContact(vector<contact> &contacts);

void writeAllContacts(vector<contact> &contacts);

void editContact(vector<contact> &contacts);

void addContact(vector<contact> &contacts);

void showAllContacts(vector<contact> &contacts);


#endif
