#include "Huffman.h"

int main()
{
    Huffman *huffman = new Huffman();
    int commend;
    string directory = "//home//matheus//Desktop//meusite//index.html";
    //cin >> directory;
    //cin >> commend;

    switch (commend) {
    case 0:
        huffman->huffmanCompress(directory);
        break;
    case 1:
        huffman->huffmanDecompress(directory);
        break;
    default:
        cout << "Erro 407" << endl;
        break;
    }

     
}
