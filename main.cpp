#include "OpenFile.h"
#include "FrequencyByte.h"
#include <string.h>

FrequencyByte frequency;

void frequencyChar(string str){
    for(unsigned int i = 0;i < str.size();i++){

        frequency.plusFrequency(str[i]);
    }}

int main()
{
    FilePro  file;
    string directory = "//home//matheus//Downloads//cadastro.php";
    // cout << "Enter directory for file:" << endl;
    // cin >> directory;
    file.setName(directory);
    cout << file.openFile() << endl;
    frequencyChar(file.openFile());
    for(int i = 0; i < 256;i++){
        frequency.printAll(i);}

}
