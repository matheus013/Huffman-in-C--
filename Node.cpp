#include "Node.h"


void Node::in(unsigned char e, long f){

}
void Node::setCode(string code){
    this->code = code;
}
void Node::createCode(char c){
    this->code += c;
 }
void Node::setFrequency(long f){
    frequency = f;
}
void Node::setElement(unsigned char c){
    element = c;
}
long Node::getFrequency(){
    return frequency;
}
unsigned char Node::getElement(){
    return element;
}
