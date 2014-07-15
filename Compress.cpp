#include "Compress.h"
#include <QVariant>
#include <QBitArray>
#include "File.h"

Compress::Compress(QString pathFile){

    path = pathFile;
    fileName = pathFile;
    for (int i = pathFile.size() -1; i >= 0; --i) {
        if (pathFile.at(i) == '/') {
            path.remove(i, pathFile.size()-i);
            path.append("/");
            fileName.remove(0,i+1);
            break;
        }
    }
}

Compress::Compress(QString pathFile, QString pathCompressedFile, QString uncompressDirectory){

    path = pathFile;
    fileName = pathFile;
    compressedFileName = pathCompressedFile;
    uncompressDirectory = uncompressDirectory;

    for (int i = pathFile.size() -1; i >= 0; --i) {
        if (pathFile.at(i) == '/') {
            path.remove(i, pathFile.size()-i);
            path.append("/");
            fileName.remove(0,i+1);
            break;
        }
    }

    if (uncompressDirectory != ""
            && uncompressDirectory.at(uncompressDirectory.size()-1) != '/') {
        uncompressDirectory.append('/');
    } else if (uncompressDirectory == "") {
        uncompressDirectory = path;
    }
}

QString Compress::trash(QString str){
    int trash = 8 - str.size()%8;
    if (trash == 8) {
        trash = 0;
    }
    for (int i = 0; i < trash; ++i) {
        str.prepend('0');
    }
    return str;
}


bool Compress::compress(){
    File * f = new File(path, fileName);
    QByteArray qba = f->read();
    if (qba != NULL) {
        QString size;
        size = qba.mid(0, 3);
        int c1 = size.at(0).unicode();
        int c2 = size.at(1).unicode();
        size.clear();

        QString s1 = trash(QString::number(c1, 2));
        QString s2 = trash(QString::number(c2, 2));
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

        QString namefile;
        for (int i = 3; i < 130; ++i) {
            if (qba[i] == '#') {
                break;
            }
            namefile.append(qba.at(i));
        }

        QString treeRep;
        treeRep = qba.mid(131, treeSize);

        Tree * tr = new Tree(treeRep);

        QString content;
        QString contentAux = qba.mid(treeSize+131, qba.size());
        for (int i = 0; i < contentAux.size(); ++i) {
            QChar simbol = contentAux.at(i);
            int unicode = simbol.unicode();
            content.append(trash(QString::number(unicode, 2)));
        }

        QByteArray decoded;
        Node * n = tr->getRoot();
        for (int i = 0; i <= content.size()-garbageSize; ++i) {
            if (n->isLeaf()) {
                decoded.append(n->getKey());
                n = tr->getRoot();
                --i;
            } else {
                if (content.at(i) == '0') {
                    n = n->getLeft();
                } else if (content.at(i) == '1') {
                    n = n->getRight();
                } else {
                    cout << "Arquivo Corrompido!";
                }
            }
        }

        f->write(decoded, uncompressDirectory + namefile);
        string outTxt = namefile.toUtf8().constData();
        cout << outTxt << " descompactado";

        return true;
    } else {
        cout << "Arquivo .huff não encontrado";
        return false;
    }
}

bool Compress::uncompress() {
    File * f = new File(path, fileName);
    QByteArray qba = f->read();
    if (qba != NULL) {
        QString size;
        size = qba.mid(0, 3);
        int c1 = size.at(0).unicode();
        int c2 = size.at(1).unicode();
        size.clear();

        QString s1 = trash(QString::number(c1, 2));
        QString s2 = trash(QString::number(c2, 2));
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

        QString namefile;
        for (int i = 3; i < 130; ++i) {
            if (qba[i] == '#') {
                break;
            }
            namefile.append(qba.at(i));
        }

        QString treeRep;
        treeRep = qba.mid(131, treeSize);

        Tree * tr = new Tree(treeRep);

        QString content;
        QString contentAux = qba.mid(treeSize+131, qba.size());
        for (int i = 0; i < contentAux.size(); ++i) {
            QChar simbol = contentAux.at(i);
            int unicode = simbol.unicode();
            content.append(trash(QString::number(unicode, 2)));
        }

        QByteArray decoded;
        Node * n = tr->getRoot();
        for (int i = 0; i <= content.size()-garbageSize; ++i) {
            if (n->isLeaf()) {
                decoded.append(n->getKey());
                n = tr->getRoot();
                --i;
            } else {
                if (content.at(i) == '0') {
                    n = n->getLeft();
                } else if (content.at(i) == '1') {
                    n = n->getRight();
                } else {
                    cout << "Arquivo Corrompido!";
                }
            }
        }

        f->write(decoded, uncompressDirectory + namefile);
        string outTxt = namefile.toUtf8().constData();
        cout << outTxt << " descompactado";

        return true;
    } else {
       cout << "Arquivo .huff não encontrado";
        return false;
    }
}

Compress::~Compress(){

}
