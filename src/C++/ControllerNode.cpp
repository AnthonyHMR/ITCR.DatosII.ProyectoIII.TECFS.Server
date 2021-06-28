//
// Created by juanpr on 25/6/21.
//

#include "ControllerNode.h"

ControllerNode::ControllerNode() {

}

void ControllerNode::receiveBook(string Query, string compressedPath, string metafile) {
    json query = json::parse(Query);
    string bookPath = "../src/Books/book.txt";
    huffman huffman(bookPath, compressedPath);
    huffman.compress();

    ifstream currentFile(metafile);
    json currentObject;
    currentFile >>currentObject;
    query["Book"]["Info"] = compressedPath;
    currentObject["Books"] += query;
    ofstream writeJson;
    writeJson.open(metafile);
    writeJson <<currentObject;
    writeJson.close();
}

void ControllerNode::searchBook(string bookName) {

}

void ControllerNode::storeBook() {

}


