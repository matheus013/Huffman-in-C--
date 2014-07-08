#ifndef ARRAYFREQUECY_H
#define ARRAYFREQUECY_H
#include "FrequencyByte.h"
#include <string>
using namespace std;

class ArrayFrequency
{
    int cont = 0;
    long valueLong[256] = {0};
    char elements[256];
    string code[256];
public:
     ArrayFrequency(){}
     ArrayFrequency(FrequencyByte byte);
     void arrayOrder();
     long getFrequency(int i);
     char getElements(int i);
     void inCode(string str, char c);
     string getCode(int i);
};

#endif // ARRAYFREQUECY_H
