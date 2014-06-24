#include "Tree.h"

void HuffTree::addNode(int id,unsigned char c){

}

void HuffTree::buildTree(ArrayFrequency *array){
    while(array->getFrequency(i) != 0){
        addNode(array->getFrequency(i),array->getElements(i));
        i++;
    }

}
