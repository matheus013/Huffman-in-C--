#ifndef CREATEHUFF_H
#define CREATEHUFF_H
#include "ArrayFrequency.h"
#include <QString>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Tree.h"
#include "HTree.h"

class Compress
{
    QString trash(QString str);
    QString path;
    QString fileName;
    QString compressedFileName;
    QString uncompressDirectory;
public:
    Compress();
    Compress(QString pathFile);
    Compress(QString pathFile, QString pathCompressedFile, QString uncompressDirectory);
    ~Compress();
    bool uncompress();
    bool compress();


};


#endif // CREATEHUFF_H
