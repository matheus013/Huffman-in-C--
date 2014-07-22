#include "Tree.h"
#include <QtCore>
#include <string.h>
#include <QString>
#include "Extra.h"

void huffhelp(){
    cout <<"huffman [comando] [LOCAL]" << endl;
    cout << endl;
    cout <<" Comandos:" << endl;
    cout <<" -h" << endl;
    cout <<"-> Lista de comandos disponiveis" << endl;
    cout <<" -c arquivoOriginal.x -o nomeDoArquivoCompactado.huff" << endl;
    cout <<"-> Compacta o arquivo para o arquivo out.huff: " << endl;
    cout <<" -c arquivoOriginal.x" << endl;
    cout <<"-> Compacta com mesmo nome no .huff:" << endl;
    cout <<" arquivoCompactado.huff" << endl;
    cout <<"-> Descompacta um arquivo .huff na pasta local: " << endl;
    cout <<" huffman arquivoCompactado.huff -d diretorio" << endl;
    cout <<"-> Descompacta um arquivo .huff no diretório indicado: " << endl;


}

int main(int argc, char* argv[]){
    int freq[256] = {0};
    string aux, aux2,aux5;
    if(argc == 5){
        if(strcmp(argv[1],"-c") == 0){
            if(strcmp(argv[3],"-o") == 0){

                aux = argv [4] ;
                aux = aux.substr(aux.length() - 5, 5);

                if(strcmp(aux.c_str(), ".huff") == 0){

                    readfile(argv[2], freq);
                    Tree* huffman = new Tree(freq);
                    huffman->writefile(argv[2]);
                    huffman->reWriteFile(argv[2], argv[4]);
                    cout << "Comprimido!!!!!" << endl;
                }
                else{
                    cout << "Erro! A extensão do arquivo de saída deverá ser '.huff' " << endl;
                }
            }
            else{
                cout << "Erro!Digite o comando -o após o nome do arquivo original." << endl;
            }
        }
        else{
            cout << "Erro! Digite o comando -c antes do nome do arquivo original" << endl;
        }
    }
    else if(argc == 3)
    {

        if(argv[1] != "-c")
        {
            aux5 = argv[2];
            size_t found = aux5.find(".");
            aux5 = aux5.substr(0, found);
            aux5 += ".huff";
            char* saida = new char[aux5.length() + 1];
            strcpy(saida, aux5.c_str());
            readfile(argv[2], freq);
            Tree* huffman = new Tree(freq);
            huffman->writefile(argv[2]);
            huffman->reWriteFile(argv[2], saida);
            cout << "Comprimido!" << endl;


            delete [] saida;
        }
        else
        {
            cout << "eRRo!! Digite o comando -c antes do nome do arquivo original" << endl;

        }
    }

    else if (argc == 2)
    {

        aux2 = argv[1];
        aux2 = aux2.substr(aux2.length() - 5, 5);


        if(aux2 == ".huff"){

            Tree* THuff = new Tree(0, false);
            THuff->readFile(argv[1]);
            THuff->rebuildOriginalFile(argv[1]);
            cout << "Descomprimido" << endl;
        }
        else{
            cout << "eRRO! A extensão do arquivo de entrada deverá ser '.huff' " << endl;
        }
    }
    else if(argc == 4){
        if (argv[2] == " -d"){
            if(aux2 == ".huff"){
                char* aux3 ;
                aux3 = argv[3];
                char* aux4;
                aux4 = argv[1];
                strcat(aux3,aux4);
                Tree* THuff = new Tree(0, false);
                THuff->readFile(aux3);
                THuff->rebuildOriginalFile(aux3);
                cout << "Descomprimido" << endl;

            }

            else{
                cout << "eRRO! A extensão do arquivo de entrada deverá ser '.huff'" << endl;
            }
        }
        else{
            cout << "eRRO!Digite o comando -d após o nome do arquivo" << endl;
        }
    }

   else{
        huffhelp();
    }

    return 0;
}
