//
// Created by Omran Suleiman on 2023-02-08.
//

#include "contact.h"


void readAllContacts(vector<contact> &contacts) {
    setlocale(LC_ALL, "sv_se");

    ifstream file("/Users/omransuleiman/Downloads/CppProject/Book_1.txt");

    string line;
    while (!file.eof()) {
        getline(file, line);
        if (line.size() < 5)
            continue;
        stringstream ss(line);
        string fName, lName, phone, Birthday, address, zip, email;
        getline(ss, fName, '|');
        getline(ss, lName, '|');
        getline(ss, phone, '|');
        getline(ss, Birthday, '|');
        getline(ss, address, '|');
        getline(ss, zip, '|');
        getline(ss, email, '|');

        contact c(fName, lName, phone, Birthday, address, zip, email);
        contacts.push_back(c);
    }
}

void searchContact(vector<contact> &contacts) {
    string name;
    cout << setw(90) << " ENTER NAME TO SEARCH THE CONTACT: ";
    cin >> name;

    setlocale(LC_ALL, "sv_se");
    transform(name.begin(), name.end(), name.begin(), towlower); // detta hjäpler att söka med båda varsel och gemener
    bool found = false;

    for (int i = 0; i < contacts.size(); i++) {
        if (name.find_first_not_of("qwertyuiopåäölkjhgfdsazxcvbnmQWERTYUIOPÅÄÖLKJHGFDSAZXCVBNM@.1234567890") !=
            string::npos) {
            cout << setw(90) << " ALLOWED CHARACTERS ARE ONLY LETTERS: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            searchContact(contacts);
            return;
        } else if (name.length() < 3) {
            cout << "\n"
                 << setw(90) << " IT MUST BE AT LEAST THREE WORDS TO SEARCH FOR CONTACT: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            searchContact(contacts);
            return;
        }

        string email = contacts[i].getEmail();
        string number = contacts[i].getphoneNumber();
        string fname = contacts[i].getfName(); // returnerar alla fnman
        string lname = contacts[i].getlName(); // returnerar alla lnman
        transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
        transform(lname.begin(), lname.end(), lname.begin(), ::tolower);
        transform(email.begin(), email.end(), email.begin(), ::tolower);
        transform(number.begin(), number.end(), number.begin(), ::tolower);

        if (fname.find(name) != string::npos) {
            // show contact
            cout << "\n\n\n"
                 << setw(130) << " " << endl;
            contacts[i].showContact();
            cout << setw(130) << " =---------------------------------------------------= " << endl;
            cout << setw(130) << " =---------------------------------------------------= " << endl;
            found = true;
        } else if (lname.find(name) != string::npos) {
            // show contact
            cout << "\n\n\n"
                 << setw(130) << " " << endl;
            contacts[i].showContact();
            cout << setw(130) << " =---------------------------------------------------= " << endl;
            cout << setw(130) << " =---------------------------------------------------= " << endl;
            found = true;
        } else if (email.find(name) != string::npos) {
            cout << "\n\n\n"
                 << setw(130) << " " << endl;
            contacts[i].showContact();
            cout << setw(130) << " =---------------------------------------------------= " << endl;
            cout << setw(130) << " =---------------------------------------------------= " << endl;
            found = true;
        } else if (number.find(name) != string::npos) {
            cout << "\n\n\n"
                 << setw(130) << " " << endl;
            contacts[i].showContact();
            cout << setw(130) << " =---------------------------------------------------= " << endl;
            cout << setw(130) << " =---------------------------------------------------= " << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "\n"
             << setw(90) << " I CANNOT FIND THIS CONTACT " << endl;
    }
}

void deleteContact(vector<contact> &contacts) {

    string phone;
    cout << setw(90) << " ENTER THE PHONE NUMBER: ";
    cin >> phone;

    setlocale(LC_ALL, "sv_se");

    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getphoneNumber() == phone) {
            for (int j = i; j < contacts.size() - 1; j++) {
                contacts[j] = contacts[j +1];
            }

            contacts.erase(contacts.begin() +1);
            cout << "\n"
                 << setw(90) << " CONTACT HAS BEEN DELETED SUCCESSFULLY:" << endl;
            return;
        }
    }

    cout << "\n"
         << setw(90) << " I CANNOT FIND THIS CONTACT: " << endl;
}

void writeAllContacts(vector<contact> &contacts) {
    setlocale(LC_ALL, "sv_se");
    // char op;
    ofstream file("/Users/omransuleiman/Downloads/CppProject/Book_1.txt");

    if (!file) {
        cout << setw(90) << " THE FILE COULD NOT BE OPENED \n";
        return;
    }

    for (int i = 0; i < contacts.size(); i++) {
        file << contacts[i].getfName()<< "|";
        file << contacts[i].getlName() << "|";
        file << contacts[i].getphoneNumber() << "|";
        file << contacts[i].getBirthday() << "|";
        file << contacts[i].getAddress() << "|";
        file << contacts[i].getZipNumber() << "|";
        file << contacts[i].getEmail() << "|";
        file << endl;
    }
    if (file.fail()) {
        cout << setw(90) << " DATA COULD NOT TRANSFER TO FILE \n";
        return;
    }
}

void editContact(vector<contact> &contacts) {
    string phone;
    cout << "\n"
         << setw(90) << " YOU SELECTED A NUMBER TO EDIT A CONTACT: " << endl;
    cout << setw(90) << " ENTER THE PHONE NUMBER: ";
    cin >> phone;
    cin.ignore();

    setlocale(LC_ALL, "sv_se");

    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getphoneNumber() == phone) {

            contacts[i].CreateContact();
            return;
        }


    }

    cout << "\n"
         << setw(90) << " I CANNOT FIND THIS CONTACT" << endl;
}

void addContact(vector<contact> &contacts) {
    setlocale(LC_ALL, "sv_se");

    contact c;
    c.CreateContact();

    contacts.push_back(c);

}

void showAllContacts(vector<contact> &contacts) {
    setlocale(LC_ALL, "sv_se");

    for (int i = 0; i < contacts.size(); i++) {
        cout << "\n"
             << setw(145) << " =-----------------------------------------------------------------------= " << endl;
        cout << setw(145) << " =-----------------------------------------------------------------------= " << endl;
        cout << setw(145) << "" << endl;
        contacts[i].showContact();
        cout << "\n"
             << setw(145) << " =-----------------------------------------------------------------------= " << endl;
        cout << setw(145) << " =-----------------------------------------------------------------------= " << endl;
    }
}