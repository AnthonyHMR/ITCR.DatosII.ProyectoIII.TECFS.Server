#ifndef ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_TCPSERVER_H
#define ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_TCPSERVER_H

#include <string>

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
};

#endif //ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_TCPSERVER_H
