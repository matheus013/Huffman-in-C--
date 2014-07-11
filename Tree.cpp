#include <QChar>
#include <QDebug>
#include <Tree.h>
#include <string>
#include <iostream>

using namespace std;

Tree::Tree() {
    root = 0;
    rep = "";
}

Tree::Tree(Node * root) {
    root = root;
}

void Tree::verifyChar(QString characters, Node * root) {
    QChar character = characters[0];
    QVariant v = character;
    bool ok;



    unsigned char character1 = v.toInt(&ok);


    if (character1 == '(') {

        Node * node = new Node();
        node->setRoot(root);
        string nodePath = root->getPath();

        if (root->getLeft() == 0) {

            nodePath.append("0");
            root->setLeft(node);
            node->setPath(nodePath);
            characters.remove(0,1);

            if(!characters.isEmpty()) {
                verifyChar(characters, node);
            }

        }
        else {
            nodePath.append("1");
            root->setRight(node);
            node->setPath(nodePath);
            characters.remove(0,1);

            if(!characters.isEmpty()) {
                verifyChar(characters, node);
            }
        }
    }
    else {

        if (character == ')') {

            characters.remove(0,1);

            if(!characters.isEmpty()) {
                verifyChar(characters, root->getRoot());
            }

        }
        else {

            Node * node = new Node(character1);
            node->setRoot(root);
            string nodePath = root->getPath();

            if (character1 == '/') {
                QChar character2 = characters.at(1);
                v = character2;
                bool ok;
                unsigned char character3 = v.toInt(&ok);

                node->setKey(character3);
                characters.remove(0,1);
            }

            if (root->getLeft() == 0) {
                nodePath.append("0");
                root->setLeft(node);
                node->setPath(nodePath);
                characters.remove(0,1);

                if(!characters.isEmpty()) {
                    verifyChar(characters, root);
                }

            }
            else {
                nodePath.append("1");
                root->setRight(node);
                node->setPath(nodePath);
                characters.remove(0,1);

                if(!characters.isEmpty()) {
                    verifyChar(characters, root);
                }
            }
        }

    }

}

Tree::Tree (string rep) {
    rep = rep;
    Node * root =  new Node();
    QString qstr = QString::fromStdString(rep);
    verifyChar(qstr, root);
    this->root = root;
}

Tree::~Tree () {
    delete root;
    rep = "";
}

void Tree::showTree() {
    preOrder(root);
}

string Tree::createRep () {
    rep = "";
    preOrderRep(root);
    return rep;
}

Node * Tree::getRoot() {
    return root;
}

void Tree::setRoot (Node * newRoot) {
    root = newRoot;
}

string Tree::getRep () {
    createRep();
    return rep;

}

int Tree::setHeight(Node * node) {
    if (!node) return -1;
    return 1 + max(setHeight(node->getLeft()), setHeight(node->getRight()));
}

void Tree::preOrder(Node *node) {
    if (node) {
        preOrder(node->getLeft());
        this->visit(node);
        preOrder(node->getRight());
    }
}

void Tree::visit(Node *node) {
    string str = "";
    if (node->getKey() != 0) {
        str += node->getKey();
    }
    else {
        str.append("[]");
    }
    for(int i = 0; i < node->getHeight(); ++i) {
        str.insert(0,1,'\\');
        str.insert(1,2,'t');

    }
    cout << str;
}


void Tree::preOrderRep(Node *node) {
    if (node) {
        if (node->getLeft() && !node->getLeft()->isLeaf()){
            rep.append("(");
        }

        preOrderRep(node->getLeft());

        if (node->getLeft() && !node->getLeft()->isLeaf()) {
            rep.append(")");
        }

        if (node->getKey() != 0) {
            if(node->getKey() == '(' || node->getKey() == ')' || node->getKey() == '/') {
                rep += '/';
            }
            rep += node->getKey();
        }

        if (node->getRight() && !node->getRight()->isLeaf()) {
            rep.append("(");
        }
        preOrderRep(node->getRight());
        if (node->getRight() && !node->getRight()->isLeaf()) {
            rep.append(")");
        }
    }
}

int Tree::max(int n1, int n2)
{
    if (n1 > n2) return n1;
    else return n2;
}
