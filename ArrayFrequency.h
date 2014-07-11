#ifndef ARRAYFREQUECY_H
#define ARRAYFREQUECY_H
#include "FrequencyByte.h"
#include <string>
using namespace std;

class ArrayFrequency
{
    int cont = 0;
    int valueint[256] = {0};
    char elements[256];
    string code[256];
public:
     ArrayFrequency(){}
     ArrayFrequency(FrequencyByte byte);
     void arrayOrder();
     int getFrequency(int i);
     char getElements(int i);
     void arrayPrint();
};

#endif // ARRAYFREQUECY_H
