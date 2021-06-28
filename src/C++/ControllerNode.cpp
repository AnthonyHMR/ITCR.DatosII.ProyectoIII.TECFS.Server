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
    ofstream metadata;
    query["Book"]["Info"] = compressedPath;
    metadata.open(metafile);
    metadata << query;
    metadata.close();
}

void ControllerNode::searchBook(string bookName) {

}

void ControllerNode::storeBook() {

}


