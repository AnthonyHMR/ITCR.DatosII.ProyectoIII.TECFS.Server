#include <iostream>

#include "TcpServer.h"

int main() {
    TcpServer *server = new TcpServer(54000, 1024);
    server->runServer();

    return 0;
}
