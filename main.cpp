#include "Huffman.h"
#include "math.h"

int main()
{
    Huffman *huffman = new Huffman();
    int commend;
    string directory = "C:\\Users\\Matheus\\Desktop\\Huffman-in-Cplusplus\\test.txt";
//    cin >> directory;
//    cin >> commend;
commend = 0;
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
