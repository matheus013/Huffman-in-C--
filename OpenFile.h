#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "FrequencyByte.h"

using namespace std;

class FilePro{
private:
    string name;
    int size;
    FrequencyByte frequencyByte;
public:
    FilePro(){}
    void setName(string name){
        this->name = name;

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
    long getF(int id){
        return frequencyByte.getFrequency(id);
    }
    string getName(){
        return name;
    }



};
