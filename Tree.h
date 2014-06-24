#ifndef HUFFTREE_H
#define HUFFTREE_H
#include "Node.h"
#include "ArrayFrequency.h"

class HuffTree {
    long f;
    unsigned char c;
    Node * root = new Node(c,f);
public:
    HuffTree();
    virtual void addNode(int id,unsigned char c) = 0;
    virtual void buildTree(ArrayFrequency *array) = 0;

    
};

#endif // HUFFTREE_H
