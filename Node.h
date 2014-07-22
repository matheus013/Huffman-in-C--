#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{
    Node* left;
    Node* right;
    int frequencia;
    bool leaf;
    bool find;
    bool qFilhos;
    int checkedChild;
    unsigned char content;

public:


    Node();
    Node(int  freq, bool l, unsigned char cont = 0);
    ~Node();
    void setCheckedChild(int val);
    int getCheckedChild();
    //"Seta" o valor booleano dos filhos
    void setqFilhos(bool valqFilhos);
    //Retorna o valor boolenao dos filhos
    bool getqFilhos();
    //Muda o valor da variavel find
    void setFind(bool con);
    //Recebe o valor da variável find
    bool getFind();
    //Recebe o valor da vairável frequência
    int getFrequencia();
    //Recebe o  valor da variável content (conteúdo do nó)
    unsigned char getContent();
    //Método booleano para identificar uma folha
    bool isLeaf();
    //Seta os filhos do nó
    void setFilhos(Node* esq, Node* dir);
    //Seta os filhos da esquerda
    void setLeftChild(Node* esq);
    //Seta os filhos da direita
    void setRightChild(Node* dir);
    //Recebe o filho da esquerda
    Node* getLeftChild();
    //Recebe o filho da direita
    Node* getRightChild();

};

#endif // NODE_H
