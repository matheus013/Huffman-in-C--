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
    void huffmanCompress(string str);
    void huffmanDecompress(string str);
};

#endif // HUFFMAN_H
