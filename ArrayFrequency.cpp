#include "ArrayFrequency.h"

ArrayFrequency::ArrayFrequency(FrequencyByte byte){
    for (int i = 0; i < 256; ++i) {
        if(byte.getFrequency(i) != 0){
            valueLong[cont] = byte.getFrequency(i);
            elements[cont] = byte.getElement(i);
            cont++;
        }
    }
    arrayOrder();
}

void ArrayFrequency::arrayOrder(){
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
long ArrayFrequency::getFrequency(int i){

    return valueLong[i];
}
char ArrayFrequency::getElements(int i){
    return elements[i];
}

