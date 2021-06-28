#ifndef ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_TCPSERVER_H
#define ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_TCPSERVER_H

#include <string>
#include "ControllerNode.h"
using namespace std;
/**
 * @class Server that manages the File System flow, executes the huffman algorithms,
 * and receives all messages from client
 */
class TcpServer {
public:
    /**
     * @brief Constructor that has a port where the server is listening requests
     * @param port integer that opens the server connection for a client
     */
    TcpServer(int port, int size);
    /**
     * @brief object destructor
     */
    ~TcpServer();
    /**
     * @brief runServer method implements a IP/TCP protocol in the server so that a required client can
     * send and receive data if needed
     */
    int runServer();
    /**
     * @brief getMessage method takes the bytesRecv attribute and stores a given chain of bytes received
     * from a client and casts them into a human readable format (string)
     */
    void getMessage();
    /**
   * @brief sendMessage method sends a stream message to the client with a given response for its request
   * @param message
   */
    void sendMessage(string message);
private:
    int port;
    int size;
    char buf[4096];
    int clientSocket;
    int bytesRecv;
    string path= "../src/Books/";
    string metadata_path = "../src/Metadata/bookInfo.json";
    int count = 1;
    ControllerNode *controllerNode;
};

#endif //ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_TCPSERVER_H
