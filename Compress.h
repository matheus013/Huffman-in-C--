#ifndef CREATEHUFF_H
#define CREATEHUFF_H
#include "ArrayFrequency.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Tree.h"
#include "HTree.h"

class Compress
{
    string trash(string str);
    string path;
    string fileName;
    string compressedFileName;
    string uncompressDirectory;
public:
    Compress(string pathFile);
    Compress(string pathFile, string pathCompressedFile, string uncompressDirectory);
    ~Compress();
    bool uncompress();
    bool compress();


};


#endif // CREATEHUFF_H
