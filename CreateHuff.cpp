#include "CreateHuff.h"

CreateHuff::CreateHuff(ArrayFrequency *array, string directory)
{int i;
    ifstream in(directory.c_str(), ios::in | ios::binary | ios::ate);
    for( i = directory.size();directory[i]!='.';i--);
    directory[i+1] = 'h',directory[i+2] = 'u',directory[i+3] = 'f',directory += 'f';
    ofstream out(directory.c_str(), std::ofstream::out | std::ofstream::app);
    if (in.is_open() && out.is_open()){
        long size = in.tellg();
        for(int i = 0; i < size; ++i){
            in.seekg(i);
            out.seekp(out.tellp());
            string str = array->getCode(in.get());
            out.write(str.c_str(),str.size());
        }
        cout << directory << endl;
    }
    else{
        cout << "Falha criando novo arquivo .huff" << endl;
    }

    in.close();
    out.close();

}
