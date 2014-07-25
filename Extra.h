#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <fstream>
using namespace std;
//Comprimi arquivo
void Compress(char* novo, char* atual, bool fase);
//Leitura e contagem
void readfile(char* path, int freq[]);
//
void integridade(char* path1, char* path2);
//Concatena nome do arquivo e diretorio
string toHuff(char* fName,char* dName);
//Retorna só nome do arqivo sem diretorio
string nFile(char* dName);
//Retorna diretorio sem nome do arquivo
char* diretory(char * str);
