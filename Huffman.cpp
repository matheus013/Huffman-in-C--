#include "Huffman.h"
#include "Tree.h"
#include "Compress.h"
#include "HTree.h"
Huffman::Huffman(QString directory){
    string str = directory.toUtf8().constData();
    huffmanCompress(str);
}
void Huffman::huffmanCompress(string directory){
    cout << "Start" << endl;
    OpenFile *file = new OpenFile(directory);
    cout << "Armazenando em Array" << endl;
    array = new ArrayFrequency(file->getFrequency());
    array->arrayPrint();
}
ArrayFrequency* Huffman::getArray(){
 return array;
}
