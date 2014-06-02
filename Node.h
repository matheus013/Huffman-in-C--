#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;
class Node
{
private:
    unsigned char element;
    string code;
    long frequency;
    Node * left;
    Node * right;
    Node * next;
    bool leaf = false;

public:
    Node(unsigned char element,long frequency){
        this->frequency = frequency;
        this->element = element;
    }
    unsigned char getElement(){
        return element;
    }
    long setFrequency(long frequency){
        this->frequency = frequency;
    }
    void setElement(unsigned char element){
        this->element = element;
    }
    void catCode(char c){
        code += c;
    }
    void setLeft(Node * left){
        this->left = left;
    }
    void setRight(Node * right){
        this->right = right;
    }
    void setLeaf(){
        if(isLeaf()){
            this->leaf = false;
        }
        if(!isLeaf()){
            this->leaf = true;
        }
    }
    bool isLeaf(){
       return leaf;
    }
};

#endif // NODE_H
