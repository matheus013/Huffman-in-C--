#ifndef QUEUE_H
#define QUEUE_H
#include <Node.h>

class Queue {
    void operator = (const Queue&) {}
    Queue(const Queue&) {}
    Node * base;
    int count;
public:
    Queue ();
    void clear();
    void enqueue(Node * node);
    Node * dequeue();
    Node * headValue();
    int length();


};

#endif // QUEUE_H
