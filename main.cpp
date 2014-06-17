#include "OpenFile.h"
#include "FrequencyByte.h"
#include "Tree.h"
#include <string.h>
#include "ArrayFrequecy.h"

int main()
{
    string directory = "//home//matheus//Documents//Huffman-in-Cplusplus//test.txt";
    //    cout << "Enter directory for file:" << endl;
    //    cin >> directory;
    OpenFile *file = new OpenFile(directory);
    ArrayFrequecy *array = new ArrayFrequecy(file->getFrequency());
    array->arrayPrint();
    
}
