#include "Huffman.h"
#include "Tree.h"
#include "CreateHuff.h"

Huffman::Huffman(){}
void Huffman::huffmanCompress(string directory){
    OpenFile *file = new OpenFile(directory);
    ArrayFrequency *array = new ArrayFrequency(file->getFrequency());
    Tree *huffmanTree = new Tree(array);
    CreateHuff huff(huffmanTree->getArrayCode(),directory);

}
void Huffman::huffmanDecompress(string str){

}
