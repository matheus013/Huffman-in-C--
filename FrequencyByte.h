#include <iostream>
#include <stdlib.h>

using namespace std;

class FrequencyByte
{
    unsigned char element[256];
    long frequency [256];

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
    void plusFrequency(unsigned char element){
        this->frequency[element]++;
    }
    
    void printAll(unsigned char element){
        if(frequency[element] == 0){}
        else{
            cout << "Frequencia: " << frequency[element] << endl;
            cout << "Elemento: " << this->element[element] << endl;
        }}


};


