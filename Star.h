#ifndef STAR_H
#define STAR_H


const int ENTRY_SZ = 256;

class Star
{
private:
    char name_[ENTRY_SZ];
    long temperature_;
    double luminosity_;
    double mass_;
    double radius_;

public:

    // Store the path name of the star catalog file
    static char filePath_[ENTRY_SZ];

    Star();
    Star(char* name);
    void SetTemperature(long temp);
    void SetLuminosity(double lum);
    void SetMass(double mass);
    void SetRadius(double rad);
    void SetTemperature(char* temp);
    void SetLuminosity(char* lum);
    void SetMass(char* mass);
    void SetRadius(char* rad);
    void PrintToConsole();
    void AppendToFile();
};

#endif // STAR_H
