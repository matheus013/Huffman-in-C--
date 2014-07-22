#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include "ArrayList.h"
#include "BitArray.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <QString>
#include <QBitArray>

using namespace std;

class Tree
{



    Node* root; //Nó raiz da árvore
    ArrayList* lista; //Lista que contém os nós da árvore
    string* codeNodes; //String que contém a codificação de cada nó
    string tree_written; //String que contém a árvore montade
    int aux;
    int sizeHeader; //Tamanhdo do cabeçalho
    int sizeLast; //Tamanho do último
    int sizeFileName;//Tamanho do arquivo
    int parada; // Parada recursão
    unsigned short sizeTree; //Tamanho da árvores
    unsigned short sizeTrash; //Tamanho do lixo
    unsigned char* header; //Cabeçalho do arquivo
    string filename; //Nome do arquivo

    //Constrói a Árvore de Huffmann
    void buildTree(int frq[]);
    //Atribui uma codificação a cada nó
    void codificar(Node* node, string temp);
    //Transforma o codigo de string para bitarray
    void codenode_to_bitarray(string codenode, BitArray *buffer);
    //representa a árvore numa string
    void writeTree(Node* node, string temp);
    // Constrói o cabeçalho
    void buildHeader(string filename);
    // Escreve o cabeçalho no arquivo
    void writeHeader(char* filename, char* pathOut);
public:


    Tree();
    Tree(int frequencia[]=0, bool compress = true);
    ~Tree();

    //Imprime a Árvore
    void printNo(Node* node, int level = 0);
    //Escreve o codigo no arquivo temporario
    void writefile(char* pathIn);
    //Rescreve o codigo no arquivo permanente
    void reWriteFile(char* filename, char* pathOut);
    // Checa se o arquivo já existe
    int checkOverWrite(char* pathOut);
    //Lê o arquivo a ser descomprimido
    void readFile(char* pathIn);
    //Lê o cabeçalho do arquivo a ser descoprimido
    void readHeader(string header);
    //Reconstrói a árvore de Huffmann
    void rebuildTree(string maestro);
    //Procura o elemento na árvore, segundo a codificação dada
    string procura(string codificacao, int *x);
    //Procura o último elemento na árvore
    string procurafinal(string codificacao);
    //Reconstrói o arquivo original
    void rebuildOriginalFile(char *pathIn);
    //Remove o lixo
    void removeTrash(string aux_s);
    //Recebe a raiz da árvore
    Node* getRoot();
    //Recebe a árvore em forma de string
    string getTree_written();

    void setTree_written(string tree);

    void equilibrar(string tree);

    int getfilenameSize()
    {
        return sizeFileName;
    }
};

#endif // TREE_H
