/* 
    Written by Kanayo Emenike
    Date : 3/11/2021
*/

//Description
    //This code is just a demo code to display a rudimentary terminal login system using
        //text files to store login info.


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int checkSelection(string selection)
{
    int conversion = -1;
    conversion = stoi(selection);
    if(conversion != 1 || conversion != 2)
    {
        return -1;
    }
    return conversion;
}

bool checkValidity(string selection) 
{
    for(int i = 0; i < selection.length(); i++)
    {
        if(!isdigit(selection[i]) || selection.length() > 1)
        {
            return false;
        }
    }
    if (checkSelection(selection) == -1)
        return false;
    return true;
}

int main() 
{

    string selection;
    bool selectionSuccess = false;

    cout << "Welcome to Kanayo's International Services\n";
    do 
    {
        cout << "Please select from the following selections:\n";
        cout << "selection 1: Register\nselection 2: Log-In\nEntry:";
        cin >> selection;
        selectionSuccess = checkValidity(selection);
        if(!selectionSuccess)
            cout << "Please enter a valid selection\n";
    } while (!selectionSuccess);

    return 0;
}