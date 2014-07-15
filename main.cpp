#include "Huffman.h"
#include "Compress.h"
void huffhelp(){
    cout <<"huffman [comando] [LOCAL]" << endl;
    cout << endl;
    cout <<" Comandos:" << endl;
    cout <<"   -h" << endl;
    cout <<"-> Lista de comandos disponiveis" << endl;
    cout <<"   -c arquivoOriginal.x -o nomeDoArquivoCompactado.huff" << endl;
    cout <<"-> Compacta o arquivo para o arquivo out.huff: " << endl;
    cout <<"   -c arquivoOriginal.x" << endl;
    cout <<"-> Compacta com mesmo nome no .huff:" << endl;
    cout <<"   arquivoCompactado.huff" << endl;
    cout <<"-> Descompacta um arquivo .huff na pasta local: " << endl;
    cout <<"   huffman arquivoCompactado.huff -d diretorio" << endl;
    cout <<"-> Descompacta um arquivo .huff no diretório indicado: " << endl;


}

int main(int argc, char *argv[]) {

    //Verificar se entrou com um comando existente
    if (argc >= 2 && argc <=5){

        QString fileName = "";
        QString compressedFileName = "";
        QString directory = "";

    //Comprimir com novo nome
        if (argc == 5) {
            if (argv[1] == "-c" && argv[3] == "-o"){
                fileName = argv[2];
                compressedFileName = argv[4];
                Compress c = Compress(fileName, compressedFileName, directory);
                c.compress();

            }
            else {
                huffhelp();
            }
        }
        //Descomprimir
        else if (argc == 4){
            if (argv[2] == "-d"){
                fileName = argv[1];
                directory = argv[3];
                Compress c = Compress(fileName, compressedFileName, directory);
                c.uncompress();

            }
            else {
                huffhelp();
            }
        }
        else if (argc == 3){
            if (argv[1] == "-c"){
                fileName = argv[2];
                compressedFileName.append(".huff");
                Compress c = Compress(fileName, compressedFileName, directory);
                c.compress();

            }
            else {
                huffhelp();
            }
        }
        else if (argc == 2){
            if (argv[1] == "-h"){
                huffhelp();
            }

        }
        else if (argc == 2){
            fileName = argv[1];
            Compress c = Compress(fileName, compressedFileName, directory);
            c.uncompress();

        }
        else {
            huffhelp();
        }


    }
    else {
        huffhelp();
    }

}
