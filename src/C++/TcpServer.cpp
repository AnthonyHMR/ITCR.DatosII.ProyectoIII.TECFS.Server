#include "TcpServer.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;

TcpServer::TcpServer(int listenPort, int memSize) : port(listenPort), size(memSize) {}

int TcpServer::runServer() {
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1) {
        cerr << "can't create a socket!";
        return -1;
    }

    // Bind the socket to IP / port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    if (bind(listening, (sockaddr *) &hint, sizeof(hint)) == -1) {
        cerr << "Can't bind to IP/port";
        return -2;
    }

    // Mark to socket for listening in
    if (listen(listening, SOMAXCONN) == -1) {
        cerr << "Can't listen!";
        return -3;
    }

    // Accept a call
    sockaddr_in client;
    char host[NI_MAXHOST];
    char svc[NI_MAXSERV];

    socklen_t clientSize = sizeof(client);

    clientSocket = accept(listening, (sockaddr *) &client, &clientSize);

    if (clientSocket == -1) {
        cerr << "Problem with client connecting!";
        return -4;
    }

    // Close the listening socket
    close(listening);

    memset(host, 0, NI_MAXHOST);
    memset(svc, 0, NI_MAXSERV);

    int result = getnameinfo((sockaddr *) &client, clientSize, host, NI_MAXHOST, svc, NI_MAXSERV, 0);

    if (result) {
        cout << host << "connected on" << svc << endl;
    } else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << "connected on" << ntohs(client.sin_port) << endl;
    }

    // While receiving display message, echo message

    while (true) {
        // Clear the buffer
        memset(buf, 0, 4096);

        // Wait for a message
        bytesRecv = recv(clientSocket, buf, 4096, 0);

        if (bytesRecv == -1) {
            cerr << "There was a connection issue" << endl;
            break;
        }

        if (bytesRecv == 0) {
            cout << "The client disconnected" << endl;
            break;
        }

        // Display message
        getMessage();

    }

    // Close socket
    close(clientSocket);
}

void TcpServer::getMessage() {
    string Query = string(buf, 0, bytesRecv);
    json query = json::parse(Query);
    if (query.contains("Search")) {
        sendMessage(to_string(this->controllerNode->searchBook(query, metadata_path)));
    }else if(query.contains("File")){
        ifstream request(metadata_path);
        json metadataFile;
        request >> metadataFile;
        string matchBook;
        for (int i = 0; metadataFile["Books"].size() != i; i++) {
            if (metadataFile["Books"][i]["Book"]["ID"] == query["File"]){
                metadataFile["Books"][i]["Book"]["Info"].get_to(matchBook);
            }
        }
        string decompressedBook = "../src/Books/decompressedBook.txt";
        huffman huffman(matchBook, decompressedBook);
        huffman.decompress();
        ifstream result(decompressedBook);
        string resultSender;
        string res;
        while(getline(result, resultSender)){
            res.append(resultSender);
        }
        sendMessage(res);
        cout << "Received: \n" << string(buf, 0, bytesRecv) << endl;
        cout << res << endl;
    }else {
        string name = path + "book.txt";
        string compressed_path = path + "compressedBook" + to_string(count) + ".huf";
        ofstream book;
        book.open(name);
        string book_content;
        query["Book"]["Info"].get_to(book_content);
        book << book_content;
        book.close();
        this->controllerNode->receiveBook(Query, compressed_path, metadata_path);
        count++;
    }
}

void TcpServer::sendMessage(string message) {


    int sendRes = send(clientSocket, message.c_str(), message.size() + 1, 0);
    if (sendRes == -1) {
        cout << "Could not send to client!\r\n";
    }
}

TcpServer::~TcpServer() {}
