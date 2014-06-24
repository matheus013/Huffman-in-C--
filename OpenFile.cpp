#include "OpenFile.h"
OpenFile::OpenFile(string name){

    this->name = name;
    openFile();
}


void OpenFile::openFile(){
    ifstream in(name.c_str(), ios::in | ios::binary | ios::ate);
    if (in.is_open()){
        size = in.tellg();
        for(int i = 0; i < size; ++i){
            in.seekg(i);
            frequencyByte.plusFrequency(in.get());
        }
    }
}

long OpenFile::sizeFile(){
    return size;
}
FrequencyByte OpenFile::getFrequency(){
    return frequencyByte;
}
string OpenFile::getName(){
    return name;
}
