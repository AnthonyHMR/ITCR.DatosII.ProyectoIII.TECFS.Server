#ifndef ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_TCPSERVER_H
#define ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_TCPSERVER_H

#include <string>
#include "ControllerNode.h"
using namespace std;

class TcpServer {
public:
    TcpServer(int port, int size);
    ~TcpServer();
    int runServer();
    void getMessage();
    void sendMessage(string message);
private:
    int port;
    int size;
    char buf[4096];
    int clientSocket;
    int bytesRecv;
    string path= "../src/Books/";
    string metadata_path = "../src/Metadata/";
    int count = 1;
    ControllerNode *controllerNode;
};

#endif //ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_TCPSERVER_H
