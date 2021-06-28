//
// Created by juanpr on 25/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_CONTROLLERNODE_H
#define ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_CONTROLLERNODE_H
#include <string>
#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
#include "huffman.h"
using namespace std;
using nlohmann::json;

class ControllerNode {
private:
    string inputBook{};
    string metadata_path = "../src/Metadata/";
    string books_path = "../src/Books/";
    int index = 0;
public:
    ControllerNode();
    void receiveBook(string Query, string fileName, string metafile);
    json searchBook(json query, string metafile);
    void storeBook();

};


#endif //ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_CONTROLLERNODE_H
