# include <QDebug>
# include <Node.h>

Node::Node() {
    left = 0;
    right = 0;
    root = 0;
    frequency = 0;
    key = 0;
    next = 0;
    height = 0;
    path = "";
}


Node::Node(unsigned char key, int frequency) {
    Node();
    this->frequency = frequency;
    this->key = key;


}

Node::Node(unsigned char key) {
    Node();
    this->key = key;

}

Node::Node(QChar key) {
    Node();
    QVariant v = key;
    bool ok;
    this->key = v.toInt(&ok);

}

Node::~Node() {
   Node();
}

void Node::setRoot(Node *root) {
    this->root = root;
}

Node * Node::getRoot() {
    return root;
}

void Node::setLeft(Node *left) {
    this->left = left;
    int h = height;
    h++;
    this->left->setHeight(h);
}

Node * Node::getLeft() {
    return left;
}

void Node::setRight(Node *right) {
    this->right = right;
    int h = height;
    h++;
    this->right->setHeight(h);
}

Node * Node::getRight() {
    return right;
}

void Node::setFrequency(int freq) {
    frequency = freq;
}

int Node::getFrequency() {
    return frequency;
}

void Node::setKey(char key) {
    this->key = key;
}

char Node::getKey() {
    return key;
}

bool Node::isLeaf() {
    if (getLeft() || getRight()) {
        return false;
    } else {
        return true;
    }

}

void Node::setNext(Node *node)
{
    next = node;
}

Node *Node::getNext()
{
    return next;
}

void Node::setHeight(int height) {
    int h = height - 1;
    if (getLeft()) getLeft()->setHeight(h);
    if (getRight()) getRight()->setHeight(h);
   this->height = height;
}

int Node::getHeight() {
    return height;
}

void Node::setPath(string path) {
    this->path = path;
}

string Node::getPath() {
    return path;
}
