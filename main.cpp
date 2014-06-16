#include "OpenFile.h"
#include "FrequencyByte.h"
#include "Tree.h"
#include <string.h>
#include "ArrayFrequecy.h"

int main()
{
    OpenFile file;
    string directory = "//home//matheus//Documents//Huffman-in-Cplusplus//test.txt";
    //    cout << "Enter directory for file:" << endl;
    //    cin >> directory;
    file.setName(directory);
    file.openFile();
    FrequencyByte  frequencyByte = file.getFrequency();
    ArrayFrequecy * array = new ArrayFrequecy(frequencyByte);
    array->arrayOrder();
    array->arrayPrint();

}
