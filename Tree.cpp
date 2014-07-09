#include "Tree.h"


Tree::Tree(ArrayFrequency *array){
    for(int i = 0;array->getFrequency(i) != 0;i++){
        addNode(array->getElements(i),array->getFrequency(i));
    }
}

void Tree::addNode(unsigned char element,long frequency){
    string code;
    while(isStatus() != true){
        if(root->right->getFrequency() < frequency){
            root = root->left;
            code += '0';
            size++;
        }
        else{
            size++;
            root->right->in(element,frequency);
            okStatus();
            code += '1';
            array->inCode(code,element);
        }
        cout << code << endl;
    }
}

ArrayFrequency* Tree::getArrayCode(){
    return array;
}
int Tree::getSize(){
    return size;
}
bool Tree::isStatus(){
    return status;
}
void Tree::okStatus(){
    status = true;
}

