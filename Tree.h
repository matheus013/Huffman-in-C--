#include "Node.h"
#include "FrequencyByte.h"

template<typename E> class HuffTree {
    Node<FrequencyByte> root;

public:
    HuffTree(){

    }

    void setRoot(E root,Node left,Node right){
        this->root.setElement(root);
        this->root.setLeft(left);
        this->root.setRight(right);
    }
    void buildTree(){

    }
    void onLeaf(Node * node){
        if(node->left == NULL && node->right == NULL){ node->leaf = true; }
    }



};
