#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "ArrayFrequency.h"
#include "OpenFile.h"
#include "Tree.h"

using namespace std;

class Huffman
{
public:
    Huffman();
    virtual void huffmanCompress(string str) = 0;
    virtual void huffmanDecompress(string str) = 0;
};

#endif // HUFFMAN_H
