#include <Queue.h>
#include <QDebug>

Queue::Queue(){
    count = 0;
    base = 0;
}

void Queue:: clear(){
    Node * current = base;
    for (int i = 0; i < count; ++i) {
        Node * aux = current->getNext();
        delete current;
        current = aux;
        delete aux;
    }
    count = 0;
}

void Queue:: enqueue(Node * node){
    if(base) {
        Node * aux = base;
        while  (aux->getNext() && aux->getFrequency() < node->getFrequency()){
            aux = aux->getNext();
        }
        node->setNext(aux->getNext());
        aux->setNext(node);
    } else {
        base = node;
    }
    ++count;
}

Node * Queue:: dequeue(){
    Node * aux = new Node(base->getKey(), base->getFrequency());
    aux->setNext(base->getNext());
    base = base->getNext();
    --count;
    return aux;
}

Node * Queue::headValue(){
    return base;
}

int Queue::length(){
    return count;
}
