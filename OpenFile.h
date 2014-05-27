#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

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
    char * openFile(){
        ifstream in(name.c_str(), ios::in | ios::binary | ios::ate);
        this->size = in.tellg();
        if( in == NULL){return NULL;}
        else{
            if (in.is_open()){
                char * str;

                in.seekg (0, in.end);
                int length = in.tellg();
                in.seekg (0, in.beg);
                str = new char [length];
                in.read (str,length);
                in.close();
                return str;
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
