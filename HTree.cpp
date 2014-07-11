#include <QDebug>
#include "HTree.h"

HuffmanTree::HuffmanTree(ArrayFrequency *array) {

    for (int i = 0; i < 256; ++i) {
        if(array->getFrequency(i) != 0){
            Node * in = new Node(array->getElements(i), array->getFrequency(i));
            FQueue->enqueue(in);
        }
    }
}

HuffmanTree::HuffmanTree() {
    hash = new QHash<unsigned char, string>();
    FQueue = new Queue();
}

HuffmanTree::~HuffmanTree() {
    FQueue = 0;
    delete tree;
}

Queue * HuffmanTree::getFQueue() {
    return FQueue;
}

void HuffmanTree::setFQueue(Queue * FQueue) {
    this->FQueue = FQueue;
}

Tree * HuffmanTree::getTree() {
    return tree;
}

void HuffmanTree::setTree(Tree * tree) {
    this->tree = tree;
}

Tree * HuffmanTree::createTree() {
    Tree * tree = new Tree();
    Node * root;
    while (FQueue->length() > 1) {
        Node * n1 = FQueue->headValue();
        FQueue->dequeue();
        Node * n2 = FQueue->headValue();
        FQueue->dequeue();
        Node * n3 = new Node();
        int n3freq = n1->getFrequency() + n2->getFrequency();
        n3->setFrequency(n3freq);
        n3->setRight(n1);
        n3->setLeft(n2);
        FQueue->enqueue(n3);
        root = n3;
    }
    tree->setRoot(root);
    int h = tree->setHeight(root);
    root->setHeight(h);
    return tree;
}


void HuffmanTree::setHash(QHash<unsigned char, string> * hash) {
    this->hash = hash;
}


QHash<unsigned char, string> *HuffmanTree::getHash() {
    return hash;
}

void HuffmanTree::createHash(Tree *tree) {

    addNodeToHash(tree->getRoot(), "");

}

void HuffmanTree::addNodeToHash(Node *node, string path) {
    if (node->isLeaf()) {
        addNodeToHash(node->getKey(), path);
    } else {
        if (node->getLeft()) {
            string path = node->getPath();
            path.append("0");
            node->getLeft()->setPath(path);
            addNodeToHash(node->getLeft(), node->getLeft()->getPath());
        }

        if (node->getRight()) {
            string path = node->getPath();
            path.append("1");
            node->getRight()->setPath(path);
            addNodeToHash(node->getRight(), node->getRight()->getPath());
        }
    }
}

void HuffmanTree::addNodeToHash(unsigned char key, string path) {
    hash->insert(key, path);
}


void HuffmanTree::showHash() {
    QList<unsigned char> keys = hash->keys();
    for (int i = 0; i < keys.size(); ++i) {
        cout << keys[i];
        cout << hash->take(keys[i]);
    }
}
