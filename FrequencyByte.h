#include <iostream>
#include <stdlib.h>

using namespace std;

class FrequencyByte{

    unsigned char element[256];
    long frequency [256] = {0};

public:
    FrequencyByte(){
        for(int i = 0;i < 256;i++){
            element[i] = i;
        }
    }

    char getElement(unsigned char element){
        return this->element[element];
    }
    long getFrequency(unsigned char element){
        return frequency[element];
    }
    void setFrequency(unsigned char frequency,int id){
        this->frequency[id] = frequency;
    }

    void plusFrequency(unsigned char element){
        this->frequency[element]++;
    }

    void printAll(unsigned char element){
        if(getFrequency(element)
                != 0){
            cout << "Frequencia: " << getFrequency(element) << endl;
            cout << "Elemento: " << getElement(element) << endl;
        }}


};


