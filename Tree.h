#ifndef TREE_H
#define TREE_H
# include <string>
# include "Node.h"
# include <QVariant>

class Tree {
    void preOrder(Node * node);
    void visit(Node * node);
    void preOrderRep(Node * node);
    int max(int n1, int n2);
    void visitRep(Node * node);
    void verifyChar(QString characters, Node * root);
    Node * root;
    string rep;
public:
    Tree();
    Tree(Node * root);
    Tree(QString rep);
    Tree(string rep);
    ~Tree();
    void showTree();
    string createRep ();
    Node * getRoot();
    void setRoot (Node * newRoot);
    string getRep();
    int setHeight(Node * node);

};

#endif // TREE_H
