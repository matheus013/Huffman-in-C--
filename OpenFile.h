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
    OpenFile(string name){

        this->name = name;
        openFile();
    }


    void openFile(){
        ifstream in(name.c_str(), ios::in | ios::binary | ios::ate);
        if (in.is_open()){
            size = in.tellg();
            for(int i = 0; i < size; ++i){
                in.seekg(i);
                frequencyByte.plusFrequency(in.get());
            }
        }
    }

    long sizeFile(){
        return size;
    }
    FrequencyByte getFrequency(){
        return frequencyByte;
    }
    string getName(){
        return name;
    }
};

#endif // OPENFILE_H
