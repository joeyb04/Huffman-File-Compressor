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
