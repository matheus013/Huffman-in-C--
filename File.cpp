
#include <QDataStream>
#include <QBitArray>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <vector>
#include <File.h>

File::File() {
    m_path = "";
    m_filename = "";
}

File::File(QString path, QString filename) {
    m_path = path;
    m_filename = filename;
}

File::~File() {
    m_path.clear();
    m_filename.clear();
}

void File:: split()
{
    int sizeMax = 4;
    QString fullpath = m_path + m_filename;

    QFile bigFile (fullpath);
    if (bigFile.exists()) {
        bigFile.open(QIODevice::ReadWrite | QIODevice::Text);
        int length = (int) bigFile.size();
        int parts = 1 + length / (sizeMax-1);
        int achunk = length/(parts-1);
        std::vector<char> buffer (achunk);

        for (int i = 0; i < parts; i++) {
            QString partialpath = m_path + QString::number(i) + m_filename;

            bigFile.read(&buffer[0], achunk);

            QFile smallFile (partialpath);
            smallFile.open(QIODevice::ReadWrite | QIODevice::Text);
            smallFile.write(&buffer[0], achunk);
            smallFile.close();

            qDebug() << partialpath;
        }
    }
}

QByteArray File::read() {
    QFile file(m_path + m_filename);
    file.open(QIODevice::ReadOnly);

    QTextStream in(&file);
    QString string = in.readAll();
    QByteArray byteArray;
    byteArray.append(string);

    return byteArray;
}


void File::write(QByteArray byteArray, QString filename) {
    QFile file(filename);
    file.open(QIODevice::ReadWrite);
    file.write(byteArray);
    file.close();
}
