#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QFile>
#include <QByteArray>

class File {
public:
    File();
    File(QString path, QString filename);
    ~File();
    void split();
    QByteArray read();
    void write(QByteArray byteArray, QString file);
private:
    QString path;
    QString filename;
};

#endif // FILE_H
