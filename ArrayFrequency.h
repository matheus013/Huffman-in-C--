#ifndef ARRAYFREQUECY_H
#define ARRAYFREQUECY_H
#include "FrequencyByte.h"
#include <string>
#include <QHash>
using namespace std;

class ArrayFrequency
{
    int cont = 0;
    long valueLong[256] = {0};
    char elements[256];
    QHash<char,string> hash;
public:
    ArrayFrequency(FrequencyByte byte);
    ArrayFrequency(){}
    void arrayOrder();
    long getFrequency(int i);
    char getElements(int i);
    void inCode(string str, char c);
    string getCode(char c);
};

#endif // ARRAYFREQUECY_H
