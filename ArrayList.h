#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>
#include <QList>
#include "Node.h"

using namespace std;


//Lista baseada em Array
class ArrayList {

    int maxSize; // Tamanho máximo da lista
    int listSize; // Número de items na lista no momento
    int curr; // Posição do elemento corrente
    Node** listArray; // Array que contem os elementos da lista

public:

    ArrayList(int size=0);
    ~ArrayList();
    int Assert(bool condition, string name);
    //Método para limpar a lista totaltmente
    void clear();
    // Insere um elemento na posição corrente
    void insert(Node* it);
    //Insere um elemento no fim da lista
    void append(Node* it);
    // Remove e retorna o elemento corrente
    Node* remove();
    //Mover o cursor para o início
    void moveToStart();
    //Mover o cursor para o fim
    void moveToEnd();
    // Move o cursor para uma posição determinada
    void moveToPos(int pos);
    //Retrocede o cursor uma posição na lista
    void prev();
    //Avança o cursor uma posição na lista
    void next();
    // Retorna o tamanho da lista
    int length();
    // Retorna a posição do cursos
    int currPos();
    //Retorna o elemento de uma determianda posição
    Node* getValue();
    //Recebe a lista
    Node** getArray();
    //Método para imprimira a lista
    void print();
    //Método para ordernar a lista
    void bubblesort();


};

#endif // ARRAYLIST_H
