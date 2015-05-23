#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include "Star.h"

char Star::filePath_[ENTRY_SZ] = "";

Star::Star()
{
    //Constructor is declared in Star.h but not needed.
}

Star::Star(char* name)
{
    strcpy(name_, name);
}

void Star::SetTemperature(long temp)
{
    temperature_ = temp;
}

void Star::SetLuminosity(double lum)
{
    luminosity_ = lum;
}

void Star::SetMass(double mass)
{
    mass_ = mass;
}

void Star::SetRadius(double rad)
{
    radius_ = rad;
}

void Star::SetTemperature(char* temp)
{
    long temp_ = 0;
    std::stringstream ss;
    ss << temp;
    ss >> temp_;
    temperature_ = temp_;
}

void Star::SetLuminosity(char* lum)
{
    double lum_ = 0;
    std::stringstream ss;
    ss << lum;
    ss >> lum_;
    luminosity_ = lum_;
}

void Star::SetMass(char* mass)
{
    double mas_ = 0;
    std::stringstream ss;
    ss << mass;
    ss >> mas_;
    mass_ = mas_;
}

void Star::SetRadius(char* rad)
{
    double rad_ = 0;
    std::stringstream ss;
    ss << rad;
    ss >> rad_;
    radius_ = rad_;
}

void Star::PrintToConsole()
{
    std::cout << name_
         << ", " << temperature_
         << ", " << luminosity_
         << ", " << mass_
         << ", " << radius_ << "\n";
}

void Star::AppendToFile()
{
    if(strcmp(Star::filePath_, "") != 0)
    {
        std::ofstream outFile;
        outFile.open(Star::filePath_, std::fstream::in | std::fstream::out | std::fstream::app);    //open file to append
        outFile << "\n" << name_
                << ", " << temperature_
                << ", " << luminosity_
                << ", " << mass_
                << ", " << radius_;
        outFile.close();
        outFile.clear(std::ios_base::goodbit);
    }
    else
    {
        std::cout << "No file to append to.\n";
    }
}
