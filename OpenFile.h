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
    virtual void openFile() = 0;
    virtual long sizeFile() = 0;
    virtual FrequencyByte getFrequency() = 0;
    virtual string getName() = 0;
};

#endif // OPENFILE_H
