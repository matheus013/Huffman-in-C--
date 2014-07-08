#include "Huffman.h"
#include "math.h"

int main()
{
    Huffman *huffman = new Huffman();
    int commend;
    string directory;
    cin >> directory;
    cin >> commend;

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
