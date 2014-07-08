#include "CreateHuff.h"


CreateHuff::CreateHuff(ArrayFrequency *array, string directory)
{
    ifstream in(directory.c_str(), ios::in | ios::binary | ios::ate);
    for(int i = directory.size();directory[i]!='.';i--){
        directory[i] = 0;
    }
    directory += "huff";
    ofstream out(directory.c_str(), std::ofstream::out | std::ofstream::app);
    if (in.is_open() && out.is_open()){
        long size = in.tellg();
        for(int i = 0; i < size; ++i){
            in.seekg(i);
            out.seekp(out.tellp());
            out.write(array->getCode(in.get()),sizeof(array->getCode(in.get())));
        }
    }
    else{
        cout << "Falha criando novo arquivo .huff" << endl;
    }

    in.close();
    out.close();

}
