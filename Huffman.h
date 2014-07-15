#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "ArrayFrequency.h"
#include "OpenFile.h"
#include "Tree.h"
#include "HTree.h"

using namespace std;

class Huffman
{
    ArrayFrequency *array;
public:
    Huffman(QString directory);
    void huffmanCompress(string str);
    ArrayFrequency *getArray();
};

#endif // HUFFMAN_H
