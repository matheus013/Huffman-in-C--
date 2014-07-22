#include "BitArray.h"


BitArray::BitArray(){
    clear();
    current = 0;
}
unsigned char* BitArray::getArray(){
    return arraybit;
}
short int BitArray::trashLenght(){
    return 8 - (current % 8);
}
long int BitArray::lenghtbit(){
    return current;
}
void BitArray::setCurrent(){
    current++;
}
long long int BitArray::getCurrent(){
    return current;
}
void BitArray::clear(){
    for(int i = 0; i < 111; i++)
    {
        arraybit[i] = 0x0000;

    }
    current = 0;

    temp = 0x0000;
}
void BitArray::setBit(string eight){
    string aux;
    unsigned int y = 0;
    y = (current)/8;

    for(int i = 0; i < 8; i++)
    {
        aux = eight.substr(i, 1);
        if(aux == "1")
        {
            temp = temp | (1 << (i % 8));
        }
        arraybit[y] = temp;
        current ++;
    }
    temp = 0x0000;
}
void BitArray::setBit(string eight, int size) {
    string aux;
    unsigned int y = 0;
    y = (current)/8;

    for(int i = 0; i < size; i++)
    {
        aux = eight.substr(i, 1);
        if(aux == "1")
        {
            temp = temp | (1 << i);
        }
        arraybit[y] = temp;
        current ++;
    }

    c = current;

    temp = 0x0000;
}



