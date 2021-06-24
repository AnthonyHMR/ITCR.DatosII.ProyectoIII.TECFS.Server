#include <iostream>
#include <string>
#include "TcpServer.h"
#include "huffman.h"
int main() {
    TcpServer *server = new TcpServer(54000, 1024);
    server->runServer();
    /*string input = "/home/juanpr/Escritorio/TEC/ITCR.DatosII.ProyectoIII.TECFS.Server/src/Books/book1.txt";
    string output = "/home/juanpr/Escritorio/TEC/ITCR.DatosII.ProyectoIII.TECFS.Server/src/Books/compressedbook1.huf";
    huffman huf(input,
                output);
    huf.compress();*/
    return 0;
}
