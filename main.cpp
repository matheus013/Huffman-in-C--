#include "OpenFile.h"
#include "FrequencyByte.h"
#include "Tree.h"
#include <string.h>

int main()
{
    OpenFile file;
    FrequencyByte  frequencyByte;
    string directory = "//home//matheus//Documents//Huffman-in-Cplusplus//test.txt";
    //    cout << "Enter directory for file:" << endl;
    //    cin >> directory;
    file.setName(directory);
    file.openFile();
    for(int i;i < 256 ; i++){
                frequencyByte.setFrequency(file.getFrequency(i),i);
    }
}
