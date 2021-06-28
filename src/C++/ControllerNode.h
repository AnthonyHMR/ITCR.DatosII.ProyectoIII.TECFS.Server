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
/**
 * @class Controller node class that stores the books and searches books
 */
class ControllerNode {

private:
    string inputBook{};
    string metadata_path = "../src/Metadata/";
    string books_path = "../src/Books/";
    int index = 0;
public:
    ControllerNode();
    /**
     * @brief function that receives books and separates them into txt file and its metadata
     * @param Query client's book query
     * @param fileName book's path
     * @param metafile metadata's path
     */
    void receiveBook(string Query, string fileName, string metafile);
    /**
     * @brief searching for a book requested by the client
     * @param query request json from client
     * @param metafile metadata's path
     * @return json match of the request
     */
    json searchBook(json query, string metafile);


};


#endif //ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_CONTROLLERNODE_H
