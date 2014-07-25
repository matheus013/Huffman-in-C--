#include "Tree.h"
#include <QtCore>
#include <string.h>
#include <QString>
#include "Extra.h"

void huffhelp(){
    cout <<"huffman [comando] [LOCAL]" << endl;
    cout << endl; cout <<" Comandos:" << endl;
    cout <<"-> Ajuda" << endl;
    cout <<" -h ou --help" << endl;
    cout <<"-> Dupla compressão" << endl;
    cout <<" -com arquivoOriginal.x" << endl;
    cout <<"-> Dupla descompressão" << endl;
    cout <<" -decom arquivoCompactado.huff" << endl;
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
    string str, str2,str5;
    if(argc == 5){ if(strcmp(argv[1],"-c") == 0){
            if(strcmp(argv[3],"-o") == 0){
                str = argv [4] ;
                str = str.substr(str.length() - 5, 5);
                if(strcmp(str.c_str(), ".huff") == 0){
                    readfile(argv[2], freq);
                    Tree* huffman = new Tree(freq);
                    huffman->writefile(argv[2]);
                    huffman->reWriteFile(argv[2], argv[4]);
                    cout << "Comprimido!!!!!" << endl;
                }
                else{
                    cout << "Erro! A extensão do arquivo de saída deverá ser '.huff' " << endl;
                    huffhelp();
                }
            }
            else{
                cout << "Erro!Digite o comando -o após o nome do arquivo original." << endl;
                huffhelp();
            }
        }
        else{
            cout << "Erro! Digite o comando -c antes do nome do arquivo original" << endl;
            huffhelp();
        }
    }
    else if(argc == 2 && (strcmp(argv[1],"-h") == 0 ||
                          strcmp(argv[1],"--help") == 0)){
        huffhelp();
    }
    else if(argc == 3){
        if(strcmp(argv[1],"-com") == 0){

            char temp[10] = "temp.huff";
            //Primeira
            Compress(temp,argv[2],false);
            //segunda
            string test;
            test.clear();
            test = nFile(argv[2]);
            char *testF = const_cast<char*>(test.c_str());
            string in = strcat(diretory(argv[2]),temp) ,
                    out = strcat(diretory(argv[2]),testF);
            cout << "in: " << in << endl;
            cout << "out: " << out << endl;
            Compress(strcat(diretory(argv[2]),testF),
                    strcat(diretory(argv[2]),temp),
                    true);
            cout << "Comprimido!!" << endl;

        }
        else if(strcmp(argv[1],"-decom") == 0){
            str2 = argv[2];
            str2 = str2.substr(str2.length() - 5, 5);
            if(str2 == ".huff"){
                cout << "Star First Decompress" << endl;
                Tree* THuff = new Tree(0, false);
                THuff->readFile(argv[2]);
                THuff->rebuildOriginalFile(argv[2]);
                cout << "End First Decompress" << endl;
                THuff = new Tree(0, false);
                cout << "Star Second Decompress" << endl;
                THuff->readFile("temp.huff");
                THuff->rebuildOriginalFile("temp.huff");
                remove("temp.huff");
                cout << "Descomprimido" << endl;
            }
            else{
                cout << "Erro! A extensão do arquivo de entrada deverá ser '.huff' " << endl;
                huffhelp();
            }
        }
        else if(strcmp(argv[1],"-c") == 0){
            str5 = argv[2];
            size_t found = str5.find(".");
            str5 = str5.substr(0, found);
            str5 += ".huff";
            char* saida = new char[str5.length() + 1];
            strcpy(saida, str5.c_str());
            readfile(argv[2], freq);
            Tree* huffman = new Tree(freq);
            huffman->writefile(argv[2]);
            huffman->reWriteFile(argv[2], saida);
            cout << "Comprimido!" << endl;
            delete [] saida;
        }
        else{
            cout << "Erro!! Digite o comando -c antes do nome do arquivo original" << endl;
            huffhelp();
        }
    }
    else if (argc == 2){
        str2 = argv[1];
        str2 = str2.substr(str2.length() - 5, 5);
        if(str2 == ".huff"){
            Tree* THuff = new Tree(0, false);
            THuff->readFile(argv[1]);
            THuff->rebuildOriginalFile(argv[1]);
            cout << "Descomprimido" << endl;
        }
        else{
            cout << "Erro! A extensão do arquivo de entrada deverá ser '.huff' " << endl;
            huffhelp();
        }
    }
    else if(argc == 4){
        if (strcmp(argv[2]," -d") == 0){
            if(str2 == ".huff"){
                char* str3 ;
                str3 = argv[3];
                char* str4;
                str4 = argv[1];
                strcat(str3,str4);
                Tree* THuff = new Tree(0, false);
                THuff->readFile(str3);
                THuff->rebuildOriginalFile(str3);
                cout << "Descomprimido" << endl;
            }
            else{
                cout << "Erro! A extensão do arquivo de entrada deverá ser '.huff'" << endl;
                huffhelp();
            }
        }
        else{
            cout << "Erro!Digite o comando -d após o nome do arquivo" << endl;
            huffhelp();
        }
    }
    else{
        huffhelp();
    }
    return 0;
}
