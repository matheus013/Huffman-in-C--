#ifndef NODE_H
#define NODE_H
#include <string>
#include <QChar>

using namespace std;
class Node {
    Node * root;
    Node * left;
    Node * right;
    Node * next;
    unsigned char key;
    int frequency;
    int height;
    string path;
public:
    Node ();
    Node (unsigned char key, int frequency);
    Node (unsigned char key);
    Node (QChar key);
    ~Node ();
    void setRoot (Node * root);
    Node * getRoot();
    void setLeft (Node * left);
    Node * getLeft();
    void setRight (Node * right);
    Node * getRight();
    void setFrequency(int frequency);
    int getFrequency();
    void setKey(char key);
    char getKey();
    bool isLeaf();
    void setNext(Node * node);
    Node * getNext();
    void setHeight(int height);
    int getHeight();
    void setPath(string path);
    string getPath();

};

#endif // NODE_H
