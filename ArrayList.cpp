#include "ArrayList.h"


ArrayList::ArrayList(int size){
    maxSize = 256;
    listSize = curr = size;
    listArray = new Node*[maxSize];
}

ArrayList::~ArrayList(){
    delete [] listArray;
}
int ArrayList::Assert(bool condition, string name){
    if(condition == false)
    {
        return -71;
    }
}

void ArrayList::clear() {
    delete [] listArray;
    listSize = curr = 0;
    listArray = new Node*[maxSize];
}
void ArrayList::insert(Node *it){
    Assert(listSize < maxSize, "Capacidade da lista excedida");
    for(int i=listSize; i>curr; i--)
        listArray[i] = listArray[i-1];
    listArray[curr] = it;
    listSize++;
}
void ArrayList::append(Node *it) {
    Assert(listSize < maxSize, "List capacity exceeded");
    listArray[listSize++] = it;
}

Node* ArrayList::remove(){
        Assert((curr>=0) && (curr < listSize), "No element");
        Node* it = listArray[curr];
        for(int i=curr; i<listSize-1; i++)
            listArray[i] = listArray[i+1];
        listSize--;
        return it;
    }

void ArrayList::moveToStart(){
    curr = 0;
}
void ArrayList::moveToEnd() {
    curr = listSize;
}
void ArrayList::moveToPos(int pos) {
    Assert ((pos>=0)&&(pos<=listSize), "Pos out of range");
    curr = pos;
}
Node* ArrayList::getValue(){
    Assert((curr>=0)&&(curr<listSize),"No current element");
    return listArray[curr];
}
void ArrayList::prev() {
    if (curr != 0) curr--;
}
void ArrayList::next(){
    if (curr < listSize) curr++;
}
Node** ArrayList::getArray(){
    return listArray;
}
void ArrayList::bubblesort() {
    for(int i =0; i < listSize; i++)
    {
        for(int j = i +1; j<listSize; j++)
        {
            if(listArray[i]->getFrequencia() > listArray[j]->getFrequencia())
            {
                Node* temp = listArray[i];
                listArray[i] = listArray[j];
                listArray[j] = temp;
                //swap(listArray[i], listArray[j]);
            }
            else if(listArray[i]->getFrequencia() == listArray[j]->getFrequencia())
            {
                if(listArray[i]->isLeaf() == true && listArray[j]->isLeaf() == false)
                {
                    Node* temp = listArray[i];
                    listArray[i] = listArray[j];
                    listArray[j] = temp;
                    //swap(listArray[i], listArray[j]);

                }
                else if(listArray[i]->isLeaf() == true && listArray[j]->isLeaf() == true)
                {
                    if(listArray[i]->getContent() > listArray[j]->getContent())
                    {
                        Node* temp = listArray[i];
                        listArray[i] = listArray[j];
                        listArray[j] = temp;
                        //swap(listArray[i], listArray[j]);

                    }
                }

            }
        }
    }
}
void ArrayList::print(){
    for(int i= 0;i < listSize; i++)
    {
        cout <<listArray[i]->getContent() << "/" << listArray[i]->getFrequencia() << " ";
    }
    cout << endl;
}
int ArrayList::length(){
    return listSize;
}
int ArrayList::currPos(){
    return curr;
}
