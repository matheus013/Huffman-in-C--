#include "ArrayFrequency.h"

ArrayFrequency::ArrayFrequency(FrequencyByte byte){
    for (int i = 0; i < 256; ++i) {
        if(byte.getFrequency(i) != 0){
            valueint[cont] = byte.getFrequency(i);
            elements[cont] = byte.getElement(i);
            cont++;
        }
    }
    arrayOrder();
}

void ArrayFrequency::arrayOrder(){
    int aux;
    char c;
    for(int i = 0; i < cont; i++)
    {
        for(int j = 0; j < cont - 1; j++)
        {
            if (valueint[j] == valueint[j + 1])
            {
                if(elements[j] > elements[j + 1]){
                    aux = valueint[j];
                    c = elements[j];
                    valueint[j] = valueint[j+1];
                    elements[j] = elements[j+1];
                    valueint[j+1] = aux;
                    elements[j+1] = c;
                }
            }
            else if (valueint[j] > valueint[j + 1])
            {
                aux = valueint[j];
                c = elements[j];
                valueint[j] = valueint[j+1];
                elements[j] = elements[j+1];
                valueint[j+1] = aux;
                elements[j+1] = c;
            }

        }
    }

}
int ArrayFrequency::getFrequency(int i){

    return valueint[i];
}
char ArrayFrequency::getElements(int i){
    return elements[i];
}

void ArrayFrequency::arrayPrint(){
    for(int i = 0; i < cont;i++){
        cout << "F: " << valueint[i] << endl << "C: " << elements[i] << endl << endl;
    }
}
