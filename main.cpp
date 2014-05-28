#include "OpenFile.h"
#include "FrequencyByte.h"
#include <string.h>

int main()
{
    OpenFile file;
    FrequencyByte frequencyByte;
    string directory;
    cout << "Enter directory for file:" << endl;
    cin >> directory;
    file.setName(directory);
    for(int i;i < 256 ; i++){
        frequencyByte.setFrequency(file.getF(i),i);

    }

}
