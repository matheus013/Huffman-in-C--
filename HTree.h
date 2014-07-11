#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include <QHash>
#include "Queue.h"
#include "Tree.h"
#include "Node.h"
#include "ArrayFrequency.h"
#include <iostream>
#include <string>

class HuffmanTree
{
    void addNodeToHash(Node * node, string path);
    void addNodeToHash(unsigned char key, string path);
    Queue * FQueue;
    ArrayFrequency array;
    Tree * tree;
    QHash<unsigned char, string> * hash;
public:
    HuffmanTree();
    HuffmanTree(ArrayFrequency *array);
    ~HuffmanTree();
    Queue * getFQueue();
    void setFQueue(Queue * FQueue);
    Tree * getTree();
    void setTree(Tree * tree);
    Tree * createTree();
    void setHash(QHash<unsigned char, string> * hash);
    QHash<unsigned char, string>*  getHash();
    void createHash(Tree * tree);
    void showHash();


};

#endif // HUFFMANTREE_H
