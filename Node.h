#ifndef NODE_H
#define NODE_H

template <typename E> class Node
{
private:
    E element;
    Node * left;
    Node * right;
    bool leaf = false;

public:
    Node(E element,Node left,Node right){
        this->element = element;
        this->left = left;
        this->right = right;
    }

    E getElement(){
        return element;
    }
    void setElement(E element){
        this->element = element;
    }
    void setLeft(Node left){
        this->left = left;
    }
    void setRight(Node right){
        this->right = right;
    }
};

#endif // NODE_H
