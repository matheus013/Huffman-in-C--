#include "Node.h"


Node::Node(){
    qFilhos = false;
    checkedChild = 0;
}
Node::Node(int freq, bool l, unsigned char cont){
    find = false;
    frequencia = freq;
    content = cont;
    leaf = l;
    left = 0;
    right = 0;
    qFilhos = false;
    checkedChild = 0;
}
void Node::setCheckedChild(int val){
    checkedChild = val;
}
Node::~Node(){

}
int Node::getCheckedChild(){
    return checkedChild;
}
void Node::setqFilhos(bool valqFilhos){
    qFilhos = valqFilhos;
}
bool Node::getqFilhos(){
    return qFilhos;
}
void Node::setFind(bool con){
    find = con;
}
bool Node::getFind(){
    return find;
}
int Node::getFrequencia(){
    return frequencia;
}
unsigned char Node::getContent(){
    return content;
}
bool Node::isLeaf(){
    return leaf;
}
void Node::setFilhos(Node *esq, Node *dir){
    left = esq;
    right = dir;
}
void Node::setLeftChild(Node *esq){
    left = esq;
}
void Node::setRightChild(Node *dir){
    right = dir;
}
Node* Node::getLeftChild(){
    return left;
}
Node* Node::getRightChild(){
    return right;
}
