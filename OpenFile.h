#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Variables.h"

using namespace std;

class FilePro{
private:
    string name;
    int size;
public:
    FilePro(){}
    void setName(string name){
        this->name = name;

    }
    void openFile(){
        ofstream temp;
        ifstream in(name.c_str(), ios::in | ios::binary | ios::ate);
        if (in.is_open()){
            size = in.tellg();
            for(int i = 0; i < size; ++i){

                in.seekg(i);
                frequency.plusFrequency(in.get());
            }

        }

    }
    long sizeFile(){
        return size;
    }
    string getName(){
        return name;
    }



};
