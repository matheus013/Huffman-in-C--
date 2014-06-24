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
public:
    ArrayFrequency(FrequencyByte byte);

    virtual void arrayOrder() = 0;
    virtual long getFrequency(int i) = 0;
    virtual char getElements(int i) = 0;
    void arrayPrint(){
        for(int i = 0; i < cont;i++){
            cout << "F: " << valueLong[i] << endl << "C: " << elements[i] << endl << endl;
        }
    }
};

#endif // ARRAYFREQUECY_H
