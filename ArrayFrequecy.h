#ifndef ARRAYFREQUECY_H
#define ARRAYFREQUECY_H
#include "FrequencyByte.h"
#include <string>
using namespace std;

class ArrayFrequecy
{
    int cont = 0;
    long valueLong[256] = {0};
    char elements[256];
public:
    ArrayFrequecy(FrequencyByte byte){
        for (int i = 0; i < 256; ++i) {
            if(byte.getFrequency(i) != 0){
                valueLong[cont] = byte.getFrequency(i);
                elements[cont] = byte.getElement(i);
                cont++;
            }
        }
    }

    void arrayOrder(){
        long aux;
        char c;
        for(int i = 0; i < cont; i++)
        {
            for(int j = 0; j < cont - 1; j++)
            {
                if (valueLong[j] > valueLong[j + 1])
                {
                    aux = valueLong[j];
                    c = elements[j];
                    valueLong[j] = valueLong[j+1];
                    elements[j] = elements[j+1];
                    valueLong[j+1] = aux;
                    elements[j+1] = c;
                }

            }
        }

    }
    long getFrequency(int i){
        return valueLong[i];
    }
    char getElements(int i){
        return elements[i];
    }
    void arrayPrint(){
        for(int i = 0; i < cont;i++){
            cout << "F: " << valueLong[i] << endl << "C: " << elements[i] << endl << endl;
        }
    }
};

#endif // ARRAYFREQUECY_H
