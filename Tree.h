#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include "ArrayFrequency.h"
#include <iostream>
#include <string>

using namespace std;


class Tree
{
public:
    Node * root = new Node();
    Tree(ArrayFrequency *array);
    ArrayFrequency *array = new ArrayFrequency();
    ~Tree();
    void addNode(unsigned char element,long frequency);
    string getCode(int i);
    void createCode(Node * node,char c);
    ArrayFrequency *getArrayCode();
};


#endif // TREE_H
