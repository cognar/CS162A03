/*
Author: Connor McCloskey
Date: 4/26/15
Assignment: 3
Description: Reads a text file creating star objects and storing them as Node objects in a linked list,
             Stars can be added to the end of the list by console, and list can be cleared.
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include "Star.h"
#include "LinkedList.h"

using namespace std;

const int NAME_SZ = 128;
LinkedList linkList;

void readFromFile();
void addStar();
void printStars();
void clearStars();

int main()
{
    bool endProg = false;
    char usrIn = ' ';

    while(!endProg)
    {
        cout << "a) Open a star catalog file.\n"
             << "b) Add a new star.\n"
             << "c) Print all star data.\n"
             << "d) Clear list.\n"
             << "e) Quit.\n";
        cin >> usrIn;
        cin.ignore();
        usrIn = tolower(usrIn);
        switch(usrIn)
        {
            case 'a':
                readFromFile();
                break;
            case 'b':
                addStar();
                break;
            case 'c':
                printStars();
                break;
            case 'd':
                clearStars();
                break;
            case 'e':
                endProg = true;
                break;
            default:
                cout << "Please enter a valid selection.\n";
        }
    }
    return 0;
}

void readFromFile()
{
    ifstream inFile;
    char name[NAME_SZ] = "";
    long temp = 0, starCount = 0;
    double lumin = 0, mass = 0, radius = 0;
    Star *newStar;

    clearStars();       //clear any residual data
    cout << "Please enter the file path.\n";
    cin >> Star::filePath_;
    inFile.open(Star::filePath_);
    while(inFile >> name)
    {
        name[strlen(name)-1] = '\0';     //strips comma from name.
        newStar = new Star(name);
        if(newStar == 0)        //Abort if memory allocation fails.
        {
            cout << "Memory allocation failed.\n";
            break;
        }
        inFile.ignore();    //ignore coma, name entry actually grabs first comma, all others are caught by ignore()
        inFile >> temp;     //read temperature
        newStar->SetTemperature(temp);
        inFile.ignore();
        inFile >> lumin;    //read luminosity
        newStar->SetLuminosity(lumin);
        inFile.ignore();
        inFile >> mass;     //read mass
        newStar->SetMass(mass);
        inFile.ignore();
        inFile >> radius;   //read radius
        newStar->SetRadius(radius);
        inFile.ignore();
        starCount++;
        linkList.AddLinkToBack(newStar);
    }
    inFile.close();
    inFile.clear(std::ios_base::goodbit);       //reset flags to prevent errors on certain compilers
    cout << "Successfully loaded " << starCount << " star entries.\n";
}

void addStar()
{
    char name[NAME_SZ] = "";
    long temp = 0;
    double lumin = 0, mass = 0, radius = 0;
    Star *newStar;

    if(strcmp(Star::filePath_, "") == 0)        //if no file is open, do nothing.
    {
        cout << "No file to write to, please load a file.\n";
        return;
    }
    cout << "Please enter the following information: \nName: ";
    cin >> name;
    newStar = new Star(name);       //instantiate star with name
    if(newStar == 0)        //Abort if memory allocation fails.
    {
        cout << "Memory allocation failed.\n";
        return;
    }
    cout << "Temperature: ";
    cin >> temp;
    newStar->SetTemperature(temp);
    cout << "Luminosity: ";
    cin >> lumin;
    newStar->SetLuminosity(lumin);
    cout << "Mass: ";
    cin >> mass;
    newStar->SetMass(mass);
    cout << "Radius: ";
    cin >> radius;
    newStar->SetRadius(radius);
    linkList.AddLinkToBack(newStar);        //add star to linked list
    newStar->AppendToFile();
}

void printStars()
{
    if(linkList.GetListLength() == 0)        //if no file is open, do nothing.
    {
        cout << "No stars have been read.\n";
        return;
    }
    Star *star = 0;
    Node *curNode = linkList.GetFirstNode();     //Set curNode to the first node in list
    while(true)
    {
        star = (Star*)(curNode->data_);     //cast void pointer as Star
        star->PrintToConsole();
        if(curNode->next_ == 0)     //next_ == 0 implies curNode == last_, prevents program from trying to read outside the linked list
        {
            break;
        }
        curNode = curNode->next_;       //Go to next node
    }
}

void clearStars()
{
    if(linkList.GetListLength() == 0)       //if no stars to clear, do nothing
    {
        return;
    }
    Star *star = 0;
    star = (Star*)(linkList.RemoveLinkFromFront());     //cast void pointer to first node as Star
    if(linkList.GetFirstNode()->next_ != 0)             //if there is a next element, call clearStars again
    {
        delete star;
        clearStars();
    }
    else        //Last Star, remove node from list and free memory
    {
        linkList.RemoveLinkFromFront();
        delete star;
    }
}
