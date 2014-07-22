#ifndef BITARRAY_H
#define BITARRAY_H
#include <iostream>
#include <string>

using namespace std;

class BitArray
{
    unsigned char arraybit[1110];
    unsigned char temp;
    long long int current;
    long long int c;

public:
    BitArray();
    //Recebe o bitarray
    unsigned char* getArray();
    //Retorna o tamanho do lixo
    short int trashLenght();
    //Retorna o tamanho do bitarray
    long int lenghtbit ();
    //"Seta" o valor do apontador
    void setCurrent();
    //Recebe o valor do apontador
    long long int getCurrent();
    //Método para limpar totalmente o bitarray
    void clear();
    //Recebe uma string com 8 elementos
    void setBit(string eight);
    //"Seta" um bit no bitarray
    void setBit(string eight, int size);

};

#endif // BITARRAY_H
