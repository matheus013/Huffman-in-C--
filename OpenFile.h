#ifndef OPENFILE_H
#define OPENFILE_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "FrequencyByte.h"

using namespace std;

class OpenFile{
private:
    string name;
    int size;
    FrequencyByte frequencyByte;
public:
     OpenFile(string name);
     void openFile();
     int sizeFile();
     FrequencyByte getFrequency();
     string getName();
};

#endif // OPENFILE_H
