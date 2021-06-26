#include <iostream>
#include <string>
#include "TcpServer.h"
#include "huffman.h"
int main() {
    TcpServer *server = new TcpServer(54000, 1024);
     server->runServer();
    /*
    string input = "/home/juanpr/Escritorio/TEC/ITCR.DatosII.ProyectoIII.TECFS.Server/src/Books/inputFile.txt";
    string output = "/home/juanpr/Escritorio/TEC/ITCR.DatosII.ProyectoIII.TECFS.Server/src/Books/compressedbook2.huf";
    huffman *huftest = new huffman(input, output);
    huftest->compress();*/
    return 0;
}
