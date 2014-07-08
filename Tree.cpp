#include "Tree.h"


Tree::Tree(ArrayFrequency *array){
    for(int i = 0;array->getFrequency(i) != 0;i++){
        addNode(array->getElements(i),array->getFrequency(i));
    }
}

void Tree::addNode(unsigned char element,long frequency){
    string code;
    while(root == 0){
        if(root->right->getFrequency() > frequency){
            root = root->left;
            code += '0';
        }
        else{
            root->right->in(element,frequency);
            code += '1';
            array->inCode(code,element);
        }
    }
}

ArrayFrequency* Tree::getArrayCode(){
    return array;
}


