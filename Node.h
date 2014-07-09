#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;
class Node {

    unsigned char element = 0;
    long frequency = 0;
        string code;
public:
    Node *left;
    Node *right;
    Node(){}
    void in(unsigned char e,long f);
    void setCode(string code);
    void setFrequency(long f);
    void setElement(unsigned char c);
    long getFrequency();
    unsigned char getElement();
        void createCode(char c);
};

#endif // NODE_H
