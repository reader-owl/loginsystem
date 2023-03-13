#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int choice;

    cout << "\n\n\t\t         Welcome to Login page       \n";
    cout << "\t\t--------        MENU         --------\n\n";

    cout << "\t Press 1 to LOGIN                " << endl;
    cout << "\t Press 2 to REGISTER             " << endl;
    cout << "\t Press 3 if Password is forgotten" << endl;
    cout << "\t Press 4 to Exit                  " << endl;

    cout << "\n\t Please enter your choice: ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "\t Thank You.\n\n";
        break;

    default:
        system("cls");
        cout << "Please select from above options." << endl;
        main();
    }

}

void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");

    cout << "\t\t Please enter Username and Password: " << endl;
    cout << "\t\t UserName: ";
    cin >> userId;
    cout << "\t\t Password: ";
    cin >> password;

    ifstream input("record.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout << userId << "- Login is successfull.";
        main();
    }
    else {
        cout << "\n Login error.. \n Please check ";
        main();
    }
}

void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");

    cout << "\n\t Enter UserName: ";
    cin >> ruserId;
    cout << "\n\t Enter Password: ";
    cin >> rpassword;

    ofstream file1("record.txt", ios::app);
    file1 << ruserId << " " << rpassword << endl;
    system("cls");

    cout << "\n\t Registration is successfull..";
    main();
}

void forgot()
{
    int option;
    system("cls");

    cout << "\t\t Forgot Password.?";
    cout << "Press 1 to search your ID by Username." << endl;
    cout << "Press 2 to go back to the Main menu." << endl;

    cout << "Enter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sid, spass;

        cout << "\n\t\t Enter the last username: ";
        cin >> suserId;

        ifstream file2("record.txt");
        while (file2 >> sid >> spass)
        {
            if (sid == suserId)
            {
                count = 1;
            }
        }
        file2.close();

        if (count == 1)
        {
            cout << "\n\n Your account is found. \n";
            cout << "\n Your password is: " << spass;
            main();
        }
        else {
            cout << "\n\tYour accont is not found.! \n";
            main();
        }
        break;
    }

    case 2:
    {
        main();
    }

    default:
        cout << "\t\t Wrong choice.! Please enter valid choice." << endl;
        forgot();
    }
}