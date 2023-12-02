
#include "contact.h"

int main() {
    std::vector<contact> contacts;


    setlocale(LC_ALL, "sv_se");


    readAllContacts(contacts);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n"
         << setw(120) << " WELCOME TO THE CONTACT LIST MANAGEMENT SYSTEM"
                         "\n";
    cout << setw(164)
         << "|=----------------------------------------------------------------------------------------------------------------------------=|  \n ";
    cout << setw(163)
         << "|=----------------------------------------------------------------------------------------------------------------------------=|  \n ";
    cout << setw(163)
         << "|=-------------W-----W----------------------------------W-E-L-C-O-M-E-------------------------------------W-----W-------------=|  \n ";
    cout << setw(163)
         << "|=-------------E-----E------------------------------------------------------------------------------------E-----E-------------=|  \n ";
    cout << setw(163)
         << "|=-------------L-----L------------------------------------------------------------------------------------L-----L-------------=|  \n ";
    cout << setw(163)
         << "|=-------------C-----C----------------------------------W-E-L-C-O-M-E-------------------------------------C-----C-------------=|  \n ";
    cout << setw(163)
         << "|=-------------O-----O------------------------------------------------------------------------------------O-----O-------------=|  \n ";
    cout << setw(163)
         << "|=-------------M-----M------------------------------------------------------------------------------------M-----M-------------=|  \n ";
    cout << setw(163)
         << "|=-------------E-----E----------------------------------W-E-L-C-O-M-E-------------------------------------E-----E-------------=|  \n ";
    cout << setw(163)
         << "|=----------------------------------------------------------------------------------------------------------------------------=|  \n ";
    cout << setw(163)
         << "|=----------------------------------------------------------------------------------------------------------------------------=|  \n ";
    cout << setw(105) << "                     PRESS ENTER TO CONTINUE... ";
    std::cin.get();

    do {

        //system("clear");
        int Val;

        // system("clear");

        cout << setw(158)
             << "[]=----------------------------------------------------------------------------------------------------=[]  \n ";
        cout << "\n"
             << setw(158)
             << "[]=---------------------------------=| CONTACT MANAGEMENT SYSTEM |=------------------------------------=[]  \n ";
        cout << "\n"
             << setw(158)
             << "[]=----------------------------------------------------------------------------------------------------=[]  \n ";
        cout << setw(157)
             << "[]=----------------------------------------------------------------------------------------------------=[]  \n ";
        cout << setw(156)
             << "[]                                                                                                      [] \n ";
        cout << setw(156)
             << "[]                              THIS IS THE MAIN MENU OF THE CONTACT LIST                               [] \n ";
        cout << setw(156)
             << "[]                                                                                                      [] \n ";
        cout << setw(157)
             << "[]=----------------------------------------------------------------------------------------------------=[]  \n ";
        cout << setw(157)
             << "[]=----------------------------------------------------------------------------------------------------=[]  \n ";

        cout << "\n"
             << setw(155)
             << "[]--==================================================================================================--[]\n";
        cout << "\n"
             << setw(166)
             << "[]=------------------------------|-[1]-| ADD A NEW CONTACT...  |---------------------------------------=[]          \n ";
        cout << "\n"
             << setw(166)
             << "[]=------------------------------|-[2]-| SHOW ALL CONTACTS...  |---------------------------------------=[]          \n ";
        cout << "\n"
             << setw(166)
             << "[]=------------------------------|-[3]-| SEARCH CONTACTS...    |---------------------------------------=[]          \n ";
        cout << "\n"
             << setw(166)
             << "[]=------------------------------|-[4]-| DELETE CONTACT...     |---------------------------------------=[]          \n ";
        cout << "\n"
             << setw(166)
             << "[]=------------------------------|-[5]-| EDIT CONTACT...       |---------------------------------------=[]          \n ";
        cout << "\n"
             << setw(166)
             << "[]=------------------------------|-[0]-| EXIT...               |---------------------------------------=[]          \n ";
        cout << "\n"
             << setw(156)
             << "[]--==================================================================================================--[]\n ";
        cout << "\n"
             << setw(120) << " CHOOSE ONE OF THE OPTIONS:[ 0 - 5 ] ";

        while (true) {

            cin >> Val;
            // cin.ignore();

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n\n"
                     << setw(121) << " ALLOWED CHARACTERS ARE ONLY NUMBERS: " << endl;
                cout << setw(120) << " CHOOSE ONE OF THE OPTIONS:[ 0 - 5 ] ";
            } else {
                break;
            }
        }

        switch (Val) {
            case 1:


                cin.ignore();
                addContact(contacts);
                writeAllContacts(contacts);
                break;

            case 2:
                // system("clear");
                cin.ignore();
                showAllContacts(contacts);
                setlocale(LC_ALL, "sv_se");

                break;

            case 3:
                // system("clear");
                cin.ignore();
                searchContact(contacts);
                break;

            case 4:
                // system("clear");
                cin.ignore();
                deleteContact(contacts);
                break;

            case 5:
                // system("clear");
                cin.ignore();
                editContact(contacts);
                break;

            case 0:
                // system("clear");
                cin.ignore();
                cout << "\n\n\n\n\n\n\n"
                     << setw(120) << " THANK YOU FOR USING THIS SERVICE: " << endl
                     << endl;
                exit(0);
                break;

            default:
                continue;
        }

        int option;

        while (true) {

            // system("clear");
            cin.ignore();
            cout << "\n\n\n\n"
                 << setw(120) << " [#]ENTER YOUR CHOICE PLEASE: \n";
            cout << setw(107) << " [1]MAIN MENU:\n ";
            cout << setw(100) << " [0]EXIT: ";
            string input;
            cin >> input;
            if (input.length() == 1 && isdigit(input[0])) {
                option = stoi(input);
                break;
            } else {

                cout << "\n"
                     << setw(145) << " THE INPUT IS INVALID, ALLOWED CHARACTERS ARE ONLY NUMBERS 1 OR 0: " << endl;
            }
        }

        while (true) {

            switch (option) {
                case 0:

                    //   system("clear");
                    cout << "\n\n\n\n\n\n\n"
                         << setw(120) << " THANK YOU FOR USING THIS SERVICE: " << endl
                         << endl;
                    writeAllContacts(contacts);
                    return 0;
                    break;

                case 1:

                    break;
                default:
                    cout << "\n"
                         << setw(156) << " THE INPUT IS INVALID, CHOOSE ONE OF THE CHOICE: " << endl;
                    cin.ignore();
                    string input;
                    getline(cin, input);
                    if (input.length() == 1 && isdigit(input[0])) {
                        option = stoi(input);
                        break;
                    } else {

                        cout << "\n"
                             << setw(156) << " THE INPUT IS INVALID, ALLOWED CHARACTERS ARE ONLY DIGITS: " << endl;
                        continue;
                    }
            }
            break;
        }
    } while (1);

}