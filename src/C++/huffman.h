//
// Created by juanpr on 23/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_HUFFMAN_H
#define ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_HUFFMAN_H

#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;


struct Node {
    /**
     * @brief Defining Huffman Tree Node struct
     */
    char data{};
    unsigned freq{};
    string code;
    Node *left, *right;
    /**
     * @brief Constructor that initializes left and right nodes
     */
    Node() {
        left = right = nullptr;
    }
};
     /**
     * @class Class that represents the implementation of huffman algorithm
     */
class huffman {
private:
    vector <Node*> arr;

    fstream inFile, outFile;

    string inFileName, outFileName;

    Node *root{};

    class Compare {
     /**
     * @class Overloads bool operator and compares the frequency between two nodes
     */
    public:
     /**
     * @brief Overloading bool operator
      * @returns comparison result
     */
        bool operator() (Node* l, Node* r)
        {
            return l->freq > r->freq;
        }
    };

    priority_queue <Node*, vector<Node*>, Compare> minHeap;
    /**
     * @brief Initializing a vector of tree nodes representing character's ascii value and initializing its frequency with 0
     */

    void createArr();
    /**
     * @brief Traversing the constructed tree to generate huffman codes of each present character
     */

    void traverse(Node*, string);
    /**
     * @brief Function to convert binary string to its equivalent decimal value
     */

    //
    int binToDec(string);
    /**
     * @brief Function to convert a decimal number to its equivalent binary string
     */

    //
    string decToBin(int);
    /**
     * @brief Reconstructing the Huffman tree while Decoding the file
     */
    //
    void buildTree(char, string&);
    /**
     * @brief Creating Min Heap of Nodes by frequency of characters in the input file
     */

    void createMinHeap();
    /**
     * @brief Constructing the Huffman tree
     */
    //
    void createTree();
    /**
    * @brief Generating Huffman codes
    */

    void createCodes();
    /**
    * @brief Saving Huffman Encoded File
    */
    //
    void saveEncodedFile();
    /**
    * @brief Saving Decoded File to obtain the original File
    */
    void saveDecodedFile();
    /**
    * @brief Reading the file to reconstruct the Huffman tree
    */
    void getTree();

public:
    /**
    * @brief Constructor
     * @param inFileName path of the input file
     * @param outFileName path of the ouput file
    */
    huffman(string inFileName, string outFileName)
    {
        this->inFileName = std::move(inFileName);
        this->outFileName = std::move(outFileName);
        createArr();
    }
    /**
    * @brief Compressing input file
    */
    //
    void compress();
    /**
    * @brief Decompressing input file
    */
    void decompress();
};


#endif //ITCR_DATOSII_PROYECTOIII_TECFS_SERVER_HUFFMAN_H
