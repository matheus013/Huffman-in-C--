#include "Compress.h"
#include <QVariant>
#include <QBitArray>
QBitArray reading(){

}

Compress::Compress(string pathFile){


}

Compress::Compress(string pathFile, string pathCompressedFile, string uncompressDirectory){


}

string Compress::trash(string str){
    int trash = 8 - str.size()%8;
    if (trash == 8) {
        trash = 0;
    }
    for (int i = 0; i < trash; ++i) {
        str.insert(0,1,'0');
    }
    return str;
}


bool Compress::compress(){
    File * f = new File(m_path, m_fileName);
    QByteArray qba = f->read();
    if (qba != NULL) {
        string size;
        size = qba.mid(0, 3);
        int c1 = size.at(0).unicode();
        int c2 = size.at(1).unicode();
        size.clear();

        string s1 = trash(string::number(c1, 2));
        string s2 = trash(string::number(c2, 2));
        size.append(s1);
        size.append(s2);

        s1.clear();
        s2.clear();
        for (int i = 0; i < 16; ++i) {
            if (i < 3) {
                s1.append(size.at(i));
            } else {
                s2.append(size.at(i));
            }
        }

        bool ok;
        int garbageSize = s1.toInt(&ok, 2);
        int treeSize = s2.toInt(&ok, 2);

        string namefile;
        for (int i = 3; i < 130; ++i) {
            if (qba[i] == '#') {
                break;
            }
            namefile.append(qba.at(i));
        }

        string treeRep;
        treeRep = qba.mid(131, treeSize);

        Tree * tr = new Tree(treeRep);

        string content;
        string contentAux = qba.mid(treeSize+131, qba.size());
        for (int i = 0; i < contentAux.size(); ++i) {
            QChar simbol = contentAux.at(i);
            int unicode = simbol.unicode();
            content.append(trash(string::number(unicode, 2)));
        }

        QByteArray decoded;
        Node * n = tr->root();
        for (int i = 0; i <= content.size()-garbageSize; ++i) {
            if (n->isLeaf()) {
                decoded.append(n->key());
                n = tr->root();
                --i;
            } else {
                if (content.at(i) == '0') {
                    n = n->left();
                } else if (content.at(i) == '1') {
                    n = n->right();
                } else {
                    cout << "Arquivo Corrompido!";
                }
            }
        }

        f->write(decoded, m_uncompressDirectory + namefile);
        cout << namefile + " descompactado";

        return true;
    } else {
        cout << "Arquivo .huff não encontrado";
        return false;
    }
}
