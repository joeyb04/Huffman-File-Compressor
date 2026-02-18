#include "Huffman.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <bitset>

Huffman::Huffman() : root(nullptr) {}

Huffman::~Huffman() {
    deleteTree(root);
}

void Huffman::deleteTree(Node* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
