//
// Created by juanpr on 25/6/21.
//

#include <iostream>
#include "ControllerNode.h"
#include <string>

using namespace std;

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

json ControllerNode::searchBook(json query, string metafile) {
    ifstream requestsFile(metafile);
    json allRequests;
    json Results;
    requestsFile >> allRequests;
    if (query["Search"]["Type"] == "Author") {
        for (int i = 0; allRequests["Books"].size() != i; i++) {
            if (allRequests["Books"][i]["Book"]["Author"] == query["Search"]["Word"]){
                Results["Results"] += allRequests["Books"][i]["Book"];
            }
        }
        return Results;
    }else if (query["Search"]["Type"] == "Title") {
        for (int i = 0; allRequests["Books"].size() != i; i++) {
            string info = allRequests["Books"][i]["Book"]["Title"];
            string search = query["Search"]["Word"];

            if (info.find(search) != std::string::npos){
                Results["Results"] += allRequests["Books"][i]["Book"];
            }
        }
        return Results;
    } else {
        for (int i = 0; allRequests["Books"].size() != i; i++) {
            if (allRequests["Books"][i]["Book"]["Date"] == query["Search"]["Word"]){
                Results["Results"] += allRequests["Books"][i]["Book"];
            }
        }
        return Results;
    }
}




