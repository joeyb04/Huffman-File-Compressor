#include <iostream>
#include <cstring>
#include "Huffman.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage:\n";
        std::cout << "Compress:   ./huffman -c <input_file> <output_file>\n";
        std::cout << "Decompress: ./huffman -d <input_file> <output_file>\n";
        return 1;
    }

    std::string mode = argv[1];
    std::string inputFile = argv[2];
    std::string outputFile = argv[3];

    Huffman huff;

    if (mode == "-c") {
        huff.compress(inputFile, outputFile);
        std::cout << "Compressed " << inputFile << " to " << outputFile << "\n";
    } else if (mode == "-d") {
        huff.decompress(inputFile, outputFile);
        std::cout << "Decompressed " << inputFile << " to " << outputFile << "\n";
    } else {
        std::cout << "Invalid mode. Use -c or -d.\n";
        return 1;
    }

    return 0;
}
