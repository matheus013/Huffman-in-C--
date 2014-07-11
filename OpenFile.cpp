#include "OpenFile.h"
OpenFile::OpenFile(string name){

    this->name = name;
    openFile();
}


void OpenFile::openFile(){
    float aux;
    ifstream in(name.c_str(), ios::in | ios::binary | ios::ate);
    if (in.is_open()){
        size = in.tellg();
        for(int i = 0; i < size; ++i){
            in.seekg(i);
            frequencyByte.plusFrequency(in.get());
            aux = i;
            int x = (aux/size)*100;
#ifdef _WIN32
            system("cls");
#endif
#ifdef __LINUX__
            system("clear");
#endif

            cout << "Reading file..." << x << "%" << endl;

        }
    }
}

int OpenFile::sizeFile(){
    return size;
}
FrequencyByte OpenFile::getFrequency(){
    return frequencyByte;
}
string OpenFile::getName(){
    return name;
}
