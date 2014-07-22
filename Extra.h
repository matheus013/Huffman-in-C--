#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <fstream>
using namespace std;

void readfile(char* path, int freq[])
{
    ifstream file;
    int y;

    file.open(path , ios::in | ios::binary | ios::ate);

    if(file.is_open()){
        int size = file.tellg();
        file.seekg(0, ios::beg);
        for(int i=0; i< size; i++){
            unsigned char x = file.get();
            y = x;
            (freq[y])++;
        }
    }
    else
    {
        cout << "TRASH!" << endl;
    }

    file.close();
}

void integridade(char* path1, char* path2)
{
    ifstream file1;
    ifstream file2;
    string buffer1;
    string buffer2;
    int x = 0;
    int y = 0;
    //    int k = 0;

    file1.open(path1, ios::in | ios::binary | ios::ate);
    file2.open(path2, ios::in | ios::binary | ios::ate);

    if(file1.is_open())
    {
        if(file2.is_open())
        {
            int size1 = file1.tellg();
            int size2 = file2.tellg();

            file1.seekg(0, ios::beg);
            file2.seekg(0, ios::beg);

            if(size1 != size2)
            {

            }
            for(int i =0 ; i < size1; i++)
            {
                buffer1 += file1.get();
                buffer2 += file2.get();

                if(buffer1.length() == 1024*8)
                {
                    if(buffer1.compare(buffer2) == 0)
                    {
                        cout << "Iguais até aki!" << endl;
                    }
                    else
                    {
                        for(int j = 0; j < 1024; j++)
                        {
                            if(buffer1[j] != buffer2[j])
                            {
                                cout << "Diferença na posição: "<< j+x << endl;
                                cout << "Buffer1: " << buffer1[j] << " Buffer2: " << buffer2[j] << endl << endl;
                                break;
                            }
                            else
                            {
                                //cout << "Sem diferença na posição: "<< j+x << endl;
                                //cout << "Buffer1: " << buffer1[j+k] << " Buffer2: " << buffer2[j] << endl << endl;
                            }
                            y = j;
                        }
                        x = y;
                        //break;
                    }

                    buffer1.clear();
                    buffer2.clear();
                }
            }

        }
        else
        {
            cout << "TRASH - Arquivo 2 não pode ser aberto" << endl;
        }
    }
    else
    {
        cout << "TRASH - Arquivo 1 não pode ser aberto!" << endl;
    }

    file2.close();
    file1.close();
}
