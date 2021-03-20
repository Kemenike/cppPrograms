/* 
    Written by Kanayo Emenike
    Date : 3/11/2021
*/

//Description
//This code is just a demo code to display a rudimentary terminal login system using
//text files to store login info.

//CPP Libraries
/*
    fstream - file reading library (input and output)
    string - different string manipulations
*/

//Description
//This code is just a demo code to display a rudimentary terminal login
//system using
//text files to store login info.

#include <iostream>
#include <fstream>
#include <string>

#define DIR "logins\\"
#define FILE_FORMAT ".txt"
#define OPTIONS_LOWERLIMIT 1
#define OPTIONS_UPPERLIMIT 2

using namespace std;

int checkSelection(string selection)
{
    //Checks to see if the integer that was returned is within range of the
    //program.
    int conversion = -1;
    conversion = stoi(selection);
    //IF statement configured like this allows easy changes to upper limit and
    //lower limit of the options.
    if ((conversion < OPTIONS_LOWERLIMIT) || (conversion > OPTIONS_UPPERLIMIT))
    {
        return -1;
    }
    return conversion;
}

bool checkValidity(string selection)
{
    //Checks to see if the entry is an integer < 999.
    //This allows for up to 999 entries.
    for (int i = 0; i < selection.length(); i++)
    {
        if (!isdigit(selection[i]) || selection.length() > 4)
        {
            return false;
        }
    }
    if (checkSelection(selection) == -1)
        return false;
    return true;
}

void new_register()
{
    //UNDER CONSTRUCTION

    //This function createse a file with the username and password given
    // [NOT IMPLEMENTED] If the username exists it will return an error to the user.
    string userName;
    string password;
    string fileName;
    ofstream userFile;
    //ifstream userNameCheck;

    cout << "Please enter your Username: ";
    cin >> userName;
    cout << "Please enter your Password: ";
    cin >> password;

    fileName = DIR + userName + FILE_FORMAT;

    userFile.open(fileName);
    if (userFile.is_open())
    {
        userFile << password;
        userFile.close();
    }
}
/*      --- UNUSED UNTILL USER CHECK IS IMPLEMENTED --- 
bool userExists(ifstream user)
{
    //UNDER CONSTRUCTION

    //This will check if there is already a user by that name.
        //Maybe make a new file to hold all of this? SQL database?
    if (user.is_open())
    {
        return true;
    }
    return false;
}
*/
void validate_login()
{
    bool validator = false;
    int attemptCOUNT = 0;
    int attemptMAX = 3;
    ifstream userFile;
    string validate_password;
    string file_name;
    string userName, password;

    cout << "Please enter your Username: ";
    cin >> userName;
    cout << "Password: ";
    cin >> password;

    file_name = DIR + userName + FILE_FORMAT;

    userFile.open(file_name);
    if (userFile.is_open())
    {
        userFile >> validate_password;
        do
        {
            attemptCOUNT++;
            if (password == validate_password)
            {
                cout << "Welcome back " << userName << endl;
                validator = true;
            }
            else
            {
                cout << "Invalid Login Credentials... Try again. ";
                cout << "--> Attempts Remaining: " << attemptMAX - attemptCOUNT + 1 << endl;
                cout << "Please enter your password: ";
                cin >> password;
            }
        } while (attemptCOUNT < attemptMAX && validator == false);
        if (!validator)
        {
            cout << "Max login attempts reached. Please try again later." << endl;
        }
        userFile.close();
    }
    else
    {
        cout << "No User found, please register using Option 1.\n";
    }
}

int main()
{
    //User Interface I/O

    string selection;
    int selection_convert = -1;
    bool selectionSuccess = false;

    cout << "Welcome to Kanayo's International Services\n";
    do
    {
        cout << "Please select from the following selections:\n";
        cout << "selection 1: Register\nselection 2: Log-In\nEntry:";
        cin >> selection;
        selectionSuccess = checkValidity(selection);
        if (!selectionSuccess)
            cout << "\n\n\nPlease enter a valid selection\n";
    } while (!selectionSuccess);

    selection_convert = checkSelection(selection);

    switch (selection_convert)
    {
    case 1:
        new_register();
        break;
    case 2:
        validate_login();
        break;
    };

    return 0;
}