#include "Huffman.h"
#include "Tree.h"
#include "Compress.h"
#include "HTree.h"
Huffman::Huffman(){}
void Huffman::huffmanCompress(string directory){
    cout << "Start" << endl;
    OpenFile *file = new OpenFile(directory);
    cout << "Armazenando em Array" << endl;
    ArrayFrequency *array = new ArrayFrequency(file->getFrequency());
    cout << "Build tree.." << endl;
    HuffmanTree * huffmanTree = new HuffmanTree(array);
    cout << "Coding" << endl;
    Compress * compress = new CreateHuff();


}
void Huffman::huffmanDecompress(string str){

}
