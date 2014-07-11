#ifndef FREQUENCYBYTE_H
#define FREQUENCYBYTE_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class FrequencyByte{

    unsigned char element[256];
    int frequency [256] = {0};

public:
    FrequencyByte();

    char getElement(unsigned char element);
    int getFrequency(unsigned char element);
    void setFrequency(unsigned char frequency,int id);
    void plusFrequency(unsigned char element);

};


#endif // FREQUENCYBYTE_H
