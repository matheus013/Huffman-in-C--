#include "Tree.h"
#include "Node.h"
#include "ArrayList.h"
#include "BitArray.h""
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <QString>
#include <QBitArray>
#include <QStack>

Tree::Tree(){}
Tree::~Tree(){}

Tree::Tree(int frequencia[], bool compress){
    if(compress == true){
        lista = new ArrayList();
        codeNodes = new string[256];
        aux = 0;
        sizeTree = 0;
        tree_written.clear();
        buildTree(frequencia);
    }
    else{
        root = new Node(0,false);
        tree_written.clear();
        sizeTree = 0;
        aux = 0;
        sizeHeader = 0;
        sizeLast = 0;
        sizeFileName = 0;
        sizeTrash = 0;
        filename.clear();
    }
}

void Tree::buildTree(int frq[]){
    for(int i = 0; i < 256; i++){
        if(frq[i] != 0){
            Node* temp = new Node(frq[i], true, i);
            lista->append(temp);
        }
    }

    while(lista->length() > 2){
        lista->bubblesort();
        lista->moveToStart();
        lista->next();
        Node* temp2 = lista->getValue();
        lista->moveToStart();
        Node* temp = new Node(lista->getValue()->getFrequencia() + temp2->getFrequencia() , false);
        lista->moveToStart();
        temp->setFilhos(lista->getValue(), temp2);
        lista->moveToStart();
        lista->remove();
        lista->moveToStart();
        lista->remove();
        lista->moveToStart();
        lista->insert(temp);
    }

    if(lista->length() == 2){
        lista->bubblesort();
        lista->moveToStart();
        lista->next();
        Node* temp2 = lista->getValue();
        lista->moveToStart();
        root = new Node(lista->getValue()->getFrequencia() + temp2->getFrequencia(), false);
        lista->moveToStart();
        root->setFilhos(lista->getValue(), temp2);
        lista->moveToStart();
    }
    else{
        cout << "TRASH!" << endl;
    }
}


void Tree::codificar(Node *node, string temp){
    if(node->isLeaf() == true){
        aux = node->getContent();
        codeNodes[aux] = temp;
    }
    else{
        temp = temp + "0";
        codificar(node->getLeftChild(), temp);
        temp = temp.substr(0, temp.length() - 1);
        temp = temp + "1";
        codificar(node->getRightChild(), temp);
    }
}

void Tree::codenode_to_bitarray(string codenode, BitArray *buffer){
    string aux;
    aux = codenode.substr(0, 8);
    reverse(aux.begin(), aux.end());
    buffer->setBit(aux, aux.length());
}

void Tree::writeTree(Node *node, string temp){
    if(node->isLeaf() == true){
        if(node->getContent() == '('){
            tree_written += "$(";
            sizeTree++;
        }
        else if(node->getContent() == ')'){
            tree_written += "$)";
            sizeTree++;
        }
        else if(node->getContent() == '$'){
            tree_written += "$$";
            sizeTree++;
        }
        else{
            tree_written += (char)node->getContent();
            sizeTree++;
        }
    }
    else{
        tree_written += "(";
        sizeTree++;
        writeTree(node->getLeftChild(), temp);
        writeTree(node->getRightChild(), temp);
        tree_written += ")";
        sizeTree++;
    }
}

void Tree::equilibrar(string tree){
    int qabre = 0;
    int qfecha = 0;
    QStack<char*> *verificador = new QStack<char*>();
    char* abre = "(";
    char* fecha = ")";

    for(int i; i < tree.length();i++){
        if(tree[i] == '('){
            qabre++;
            verificador->push(abre);
        }
        else if(tree[i] == ')'){
            qfecha++;
            if(verificador->size() != 0){
                if(verificador->top() == "("){
                    verificador->pop();
                }
                else{
                    verificador->push(fecha);
                }
            }
            else{
                verificador->push(fecha);
            }
        }
    }
}

void Tree::buildHeader(string filename){
    string aux_s;
    string aux_s2;
    BitArray *bit = new BitArray();
    int aux_bit;
    int k;
    aux_s.clear();
    writeTree(root, aux_s);
    aux_s.clear();
    tree_written = tree_written.substr(1,tree_written.length()-2);
    sizeTree = tree_written.length();
    equilibrar(tree_written);

    switch (sizeTrash) {
    case 1:
        aux_s = "001";
        break;
    case 2:
        aux_s = "010";
        break;
    case 3:
        aux_s = "011";
        break;
    case 4:
        aux_s = "100";
        break;
    case 5:
        aux_s = "101";
        break;
    case 6:
        aux_s = "110";
        break;
    case 7:
        aux_s = "111";
        break;
    case 8:
        aux_s = "000";
    default:
        break;
    }
    aux_bit = sizeTree/2;
    if(sizeTree%2 == 1){
        aux_s2 = "1";
    }
    else if(sizeTree%2 == 0){
        aux_s2 = "0";
    }

    aux_bit = sizeTree;

    while(aux_bit > 1){
        aux_bit = aux_bit/2;
        if(aux_bit % 2 == 1){
            aux_s2 += "1";
        }
        else if(aux_bit % 2 == 0){
            aux_s2 += "0";
        }
    }

    aux_bit = 13 - aux_s2.length();
    reverse(aux_s2.begin(), aux_s2.end());
    for(int i=0; i < aux_bit; i++){
        aux_s += "0";
    }

    aux_s += aux_s2;
    codenode_to_bitarray(aux_s.substr(0,8), bit);
    codenode_to_bitarray(aux_s.substr(8,8), bit);
    aux_s.clear();
    k = 3 + filename.length() + sizeTree;
    header = new unsigned char[k];
    header = bit->getArray();
    unsigned char c = filename.length();
    header[2] = c;

    int w =0;
    for(int i =0; i<filename.length();i++){
        w = i +3;
        header[w] = filename[i];
    }
    w = 0;
    int j = 3 + filename.length();
    for(int i = 0;i< sizeTree;i++){
        w = i+j;
        header[w] = tree_written[i];
    }

    sizeHeader = k;
    sizeFileName = filename.length();

    for(int i=0;i<k;i++);

}

void Tree::writeHeader(char *filename, char *pathOut){
    buildHeader(filename);
    ofstream out;
    out.open(pathOut, ios::out | ios::binary);

    if(out.is_open()){
        for(int i=0;i< sizeHeader;i++){
            out << header[i];
        }
    }
    else{
        cout << "TRASH!" << endl;
    }
    out.close();
}

void Tree::printNo(Node *node, int level){
    if(node != 0){
        printNo(node->getRightChild(), level + 1);
        cout << qPrintable(QString("\t").repeated(level)) << node->getContent() << "/" << node->getFrequencia() << endl;
        printNo(node->getLeftChild(), level + 1);
    }
}

void Tree::writefile(char *pathIn){
    ifstream file;
    ofstream write;
    string aux;
    string aux2;
    string temporaria;
    int sobra = 0;
    int sizefile = 0;
    BitArray *buffer = new BitArray();

    aux.clear();
    temporaria.clear();
    codificar(root, aux);
    aux.clear();

    file.open(pathIn , ios::in | ios::binary | ios::ate);

    if(file.is_open()){

        int size = file.tellg();
        file.seekg(0, ios::beg);
        int i;
        int iw =1;

        for(i=0; i< size; i++){
            unsigned char c = file.get();
            int j = c;
            aux += codeNodes[j];
            if(aux.length() >= 1024*8){
                sobra = aux.length() - 1024*8;
                temporaria = aux.substr(1024*8, sobra);
                for(int k = 0;k < (aux.length()/8); k++){
                    int n = k*8;
                    aux2 = aux.substr(n, 8);
                    codenode_to_bitarray(aux2, buffer);

                }
                iw++;
                write.open("temp.huff", ios::out | ios::binary | ios::app);
                if(write.is_open()){
                    for(int z = 0;z < aux.length()/8;z++){
                        write << buffer->getArray()[z];
                        sizefile++;
                    }
                }

                write.close();
                aux.clear();
                aux = temporaria;
                buffer->clear();
            }
        }
        int y = (aux.length()/8);
        sobra = aux.length() - (y*8);
        aux2 = aux.substr(y*8,sobra);
        string teste = aux2;


        for(int k = 0;k < (aux.length()/8); k++){
            int n = k*8;
            aux2 = aux.substr(n, 8);
            codenode_to_bitarray(aux2, buffer);

        }

        int u = 8 - sobra;
        sizeTrash = u;
        aux2 = teste;

        for(int i = 0;i < u;i++){
            aux2 += '0';
        }

        codenode_to_bitarray(aux2, buffer);

        sizeLast = (buffer->getCurrent() / 8);
        sizeLast--;

        write.open("temp.huff", ios::out | ios::binary | ios::app);

        if(write.is_open()){
            for(int z=0; z <= sizeLast;z++){
                write << buffer->getArray()[z];

                sizefile++;
            }
        }
        write.close();

        sizeTrash = buffer->trashLenght();


        buffer->clear();

    }
    else cout << "TRASH!in WriteFile" << endl;
    file.close();

}

void Tree::reWriteFile(char *filename, char *pathOut){

    writeHeader(filename, pathOut);
    //printNo(root);
    ifstream ler;
    ofstream write;
    int size2 = 0;
    ler.open("temp.huff", ios::in | ios::binary | ios::ate);

    if(ler.is_open()) {
        int size = ler.tellg();
        ler.seekg(0, ios::beg);
        unsigned char c[1101*10];
        for(int i=0; i < size; i++){

            c[size2] = ler.get();
            size2++;

            if(size2 == 1024) {
                write.open(pathOut, ios::out | ios::binary | ios::app);
                if(write.is_open()){


                    for(int j=0 ;j < size2;j++){
                        write << c[j];

                    }
                    write.close();
                }
                for(int k=0;k < size2;k++){
                    c[k] = 0x0000;
                }
                size2 = 0;
            }
        }
        write.open(pathOut, ios::out | ios::binary | ios::app);
        if(write.is_open()){
            for(int j=0 ;j <= sizeLast;j++){
                write << c[j];
            }
            write.close();
        }
        ler.close();
    }
    else{
        cout << "TRASH!" << endl;
    }

    if( remove("temp.huff") != 0){
        perror("TRASH deleting file");
    }
}

int Tree::checkOverWrite(char *pathOut){
    ifstream file;
    file.open(pathOut, ios::in | ios::binary | ios::ate);
        if(file.is_open()){
        cout << "TRASH!\tArquivo Existente\n" << endl;
        file.close();
        return -1;
    }
    else{
        return 1;
    }
}

void Tree::readFile(char *pathIn){
    ifstream file;
    string info;
    file.open(pathIn, ios::in | ios::binary | ios::ate);
    if(file.is_open()){
        file.seekg(0, ios::beg);

        for(int i = 0; i < 3; i++){
            info += file.get();
        }
        readHeader(info);
        info.clear();

        for(int i = 0; i < sizeFileName; i++){
            filename += file.get();
        }

        for(int i = 0; i < sizeTree; i++){
            tree_written += file.get();
        }

    }
    else{
        cout << "TRASH!" << endl;
    }

    file.close();
}

int binarioParaDecimal(string str){
    reverse(str.begin(), str.end());
    int retorno = 0;
    const char *c;
    c = str.c_str();

    for(int i = 0;i < str.length();i++){
        if(c[i] == '1'){
            retorno += pow(2.0,i);
        }
    }

    return retorno;
}

string charParaString(const unsigned char c){
    int byte = (int)c;
    int aux_i;
    string retorno;
    retorno.clear();

    aux_i = byte/2;

    if(byte%2 == 1){
        retorno += '1';
    }
    else if(byte%2 == 0){
        retorno += '0';
    }

    aux_i = byte;

    while(aux_i > 1){
        aux_i = aux_i/2;
        if(aux_i%2 == 1){
            retorno += '1';
        }
        else if(aux_i%2 == 0){
            retorno += '0';
        }
    }

    int sobra = 8 - retorno.length();

    if(sobra > 0)
    {
        for(int i = 0; i < sobra;i++)
        {
            retorno += '0';
        }
    }


    reverse(retorno.begin(), retorno.end());

    return retorno;
}

void Tree::readHeader(string header){
    int byte1 = 0;
    int aux_i = 0;
    const char* c;
    unsigned char aux_uc;
    string aux_s, aux_s2;
    string trash;
    string tree_length;
    aux_s.clear();

    aux_s = header[0];
    c = aux_s.c_str();
    aux_uc = c[0];
    byte1 = (int)aux_uc;

    aux_s.clear();

    aux_i = byte1/2;
    if(byte1%2 == 1){
        aux_s += "1";
    }
    else if(byte1%2 == 0){
        aux_s += "0";
    }

    aux_i = byte1;
    while(aux_i > 1){
        aux_i = aux_i/2;
        if(aux_i%2 == 1){
            aux_s += "1";
        }
        else if(aux_i%2 == 0){
            aux_s += "0";
        }
    }

    if(aux_s.length() < 8){
        int j = 0;
        j = 8 - aux_s.length();
        for(int i = 0; i < j;i++){
            aux_s += "0";
        }
    }

    reverse(aux_s.begin(),aux_s.end());
    trash = aux_s.substr(0,3);
    sizeTrash = binarioParaDecimal(trash);
    tree_length = aux_s.substr(3,5);
    aux_s2 = header[1];
    const char* ch = aux_s2.c_str();
    const char cz = ch[0];
    tree_length += charParaString(cz);
    sizeTree = binarioParaDecimal(tree_length);
    aux_s2 = header[2];
    ch = aux_s2.c_str();
    const char cw = ch[0];
     aux_s = charParaString(cw);
    sizeFileName = binarioParaDecimal(aux_s);
    parada = sizeFileName + 3 + sizeTree;

}

void Tree::rebuildTree(string maestro){
    QStack<Node*>* arranjador = new QStack<Node*>();
    arranjador->push(root);

    for(int i = 0; i < maestro.length(); i++){

        if(maestro[i] == '$'){
            i++;
            if(arranjador->top()->getqFilhos() == false){
                Node* temp = new Node(0,true,maestro[i]);
                arranjador->top()->setLeftChild(temp);
                arranjador->top()->setqFilhos(true);
            }
            else if(arranjador->top()->getqFilhos() == true){
                Node* temp = new Node(0,true,maestro[i]);
                arranjador->top()->setRightChild(temp);
                arranjador->top()->setqFilhos(false);
            }
        }
        else{
            if(maestro[i] == '('){
                if(arranjador->top()->getqFilhos() == false){
                    Node* temp = new Node(i,false);
                    arranjador->top()->setLeftChild(temp);

                    arranjador->top()->setqFilhos(true);
                    arranjador->push(temp);
                }
                else if(arranjador->top()->getqFilhos() == true){
                    Node* temp = new Node(i,false);
                    arranjador->top()->setRightChild(temp);
                    arranjador->top()->setqFilhos(false);
                    arranjador->push(temp);
                }
            }
            else if(maestro[i] == ')'){
                arranjador->pop();
            }
            else{
                if(arranjador->top()->getqFilhos() == false){
                    Node* temp = new Node(0,true,maestro[i]);
                    arranjador->top()->setLeftChild(temp);
                    arranjador->top()->setqFilhos(true);
                }
                else if(arranjador->top()->getqFilhos() == true){
                    Node* temp = new Node(0,true,maestro[i]);
                    arranjador->top()->setRightChild(temp);
                    arranjador->top()->setqFilhos(false);
                }
            }
        }
    }

    if(arranjador->size()!= 1){
        cout << "TRASH! arvore desequilibrada" << endl;
    }
}
string Tree::procura(string codificacao, int *x){
    unsigned char buffer;
    string aux_s;
    aux_s.clear();
    ofstream write;
    int j= 0;
    const char* aux_ch = filename.c_str();
    write.open(aux_ch, ios::out | ios::binary | ios::app);

    if(write.is_open()){


        QStack<Node*>* StackdeCodigo = new QStack<Node*>();
        StackdeCodigo->push(root);

        for(int i = 0; i < codificacao.length();i++){
            if(j == 100){
                int sobra = 1024 - i;
                aux_s = codificacao.substr(i+1,sobra);

                return aux_s;
            }
            else{
                x++;
                Node* temp = new Node();
                if(codificacao[i] == '0'){
                    temp = StackdeCodigo->top()->getLeftChild();
                    if(temp->isLeaf() == false){
                        StackdeCodigo->push(temp);
                    }
                    else{
                        buffer = temp->getContent();
                        StackdeCodigo->clear();
                        StackdeCodigo->push(root);
                        write << buffer;
                        j++;
                    }
                }
                else if(codificacao[i] == '1'){
                    temp = StackdeCodigo->top()->getRightChild();
                    if(temp->isLeaf() == false){
                        StackdeCodigo->push(temp);
                    }
                    else{
                        buffer = temp->getContent();
                        StackdeCodigo->clear();
                        StackdeCodigo->push(root);

                        write << buffer;
                        j++;
                    }
                }
            }
        }
    }
    else{
        cout << "TRASH!" << endl;
    }

    write.close();

    return aux_s;
}

string Tree::procurafinal(string codificacao){
    unsigned char buffer;
    string aux_s;
    aux_s.clear();
    ofstream write;
    const char* aux_ch = filename.c_str();
    write.open(aux_ch, ios::out | ios::binary | ios::app);

    if(write.is_open()){
        QStack<Node*>* StackdeCodigo = new QStack<Node*>();
        StackdeCodigo->push(root);

        for(int i = 0; i < codificacao.length();i++){
            Node* temp = new Node();
            if(codificacao[i] == '0'){

                temp = StackdeCodigo->top()->getLeftChild();
                if(temp->isLeaf() == false){
                    StackdeCodigo->push(temp);
                }
                else{
                    buffer = temp->getContent();
                    StackdeCodigo->clear();
                    StackdeCodigo->push(root);
                    write << buffer;
                }
            }
            else if(codificacao[i] == '1'){
                temp = StackdeCodigo->top()->getRightChild();
                if(temp->isLeaf() == false){
                    StackdeCodigo->push(temp);
                }
                else{
                    buffer = temp->getContent();
                    StackdeCodigo->clear();
                    StackdeCodigo->push(root);
                    write << buffer;
                }
            }
        }
    }
    else
    {
        cout << "TRASH!" << endl;
    }
    write.close();
    return aux_s;
}

void Tree::rebuildOriginalFile(char *pathIn)
{
    string info, aux_s,aux_s2;
    ifstream file;
    unsigned char* buffer;

    info.clear();


    rebuildTree(tree_written);
    //printNo(root);
    equilibrar(tree_written);

    file.open(pathIn, ios::in | ios::binary | ios::ate);

    if(file.is_open()){
        int size = file.tellg();
        file.seekg(0, ios::beg);

        buffer = new unsigned char[size];

        for(int i = 0; i < parada; i++){
            file.get();
        }

        for(int i = parada;i < size-1;i++){
            unsigned char ch = file.get();
            const unsigned char c = (const unsigned char)ch;
            info += charParaString(c);
        }

        aux_s = info;

        const char c = file.get();

        aux_s2 = charParaString(c);
        removeTrash(aux_s2);
        aux_s += aux_s2;
        procurafinal(aux_s);


    }
    else
    {
        cout << "TRASH!" << endl;
    }

    file.close();

}

void Tree::removeTrash(string aux_s){
    int i = aux_s.length() - sizeTrash;
    aux_s = aux_s.substr(0,i);
}

Node *Tree::getRoot(){
    return root;
}

string Tree::getTree_written(){
    return tree_written;
}

void Tree::setTree_written(string tree){
    tree_written = tree;
}
