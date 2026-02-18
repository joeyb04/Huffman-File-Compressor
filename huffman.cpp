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

void Huffman::generateCodes(Node* root, std::string str) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }
    generateCodes(root->left, str + "0");
    generateCodes(root->right, str + "1");
}

Node* Huffman::buildTree(const std::map<char, int>& freq) {
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;

    for (auto const& [key, val] : freq) {
        pq.push(new Node(key, val));
    }
