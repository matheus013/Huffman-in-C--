#include "Huffman.h"
#include "Tree.h"

Huffman::Huffman(){}
void Huffman::huffmanCompress(string directory){
    OpenFile *file = new OpenFile(directory);
    ArrayFrequency *array = new ArrayFrequency(file->getFrequency());
    Tree *huffmanTree = new Tree(array);
    huffmanTree->getArrayCode();

}
void Huffman::huffmanDecompress(string str){

}
