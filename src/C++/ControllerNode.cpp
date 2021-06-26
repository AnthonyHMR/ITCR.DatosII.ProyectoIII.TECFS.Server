//
// Created by juanpr on 25/6/21.
//

#include "ControllerNode.h"

ControllerNode::ControllerNode() {

}

void ControllerNode::receiveBook(string Query, string fileName, string metafile) {
    json query = json::parse(Query);
    ofstream book;
    ofstream metadata;
    string book_content;
    book.open(fileName);
    query["Book"]["Info"].get_to(book_content);
    query["Book"]["Info"] = fileName;
    book << book_content;
    metadata.open(metafile);
    metadata << query;
    book.close();
    metadata.close();
}

void ControllerNode::searchBook(string bookName) {

}

void ControllerNode::storeBook() {

}


