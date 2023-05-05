﻿#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include "BinTree.h"
#include "Bitmap.h"

using namespace std;

// 定义Huffman节点结构体
struct HuffmanNode {
    char ch; // 字符
    int freq; // 出现频率
    HuffmanNode* left; // 左子节点
    HuffmanNode* right; // 右子节点
    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// 定义比较函数，用于构建Huffman树时的优先队列
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

// 构建Huffman树
HuffmanNode* buildHuffTree(const string& str) {
    // 统计每个字符出现的频率
    unordered_map<char, int> freqMap;
    for (char c : str) {
        freqMap[c]++;
    }

    // 构建优先队列，按照频率从小到大排序
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for (auto& p : freqMap) {
        pq.push(new HuffmanNode(p.first, p.second));
    }

    // 构建Huffman树
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();
        HuffmanNode* parent = new HuffmanNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    return pq.top();
}

// 递归遍历Huffman树，生成编码表
void generateCodes(HuffmanNode* root, string code, unordered_map<char, string>& codeMap) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        codeMap[root->ch] = code;
    }
    generateCodes(root->left, code + "0", codeMap);
    generateCodes(root->right, code + "1", codeMap);
}

// Huffman编码
string huffmanEncode(const string& str, unordered_map<char, string>& codeMap) {
    string encodedStr = "";
    for (char c : str) {
        encodedStr += codeMap[c];
    }
    return encodedStr;
}

int main() {
    // 构建Huffman树
    string str = "I have a dream that one day this nation will rise up and live out the true meaning of its creed: We hold these truths to be self-evident, that all men are created equal.";
    HuffmanNode* root = buildHuffTree(str);

    // 生成编码表
    unordered_map<char, string> codeMap;
    generateCodes(root, "", codeMap);

    // 对dream进行编码
    string dreamCode = codeMap['d'] + codeMap['r'] + codeMap['e'] + codeMap['a'] + codeMap['m'];
    cout << "dream的编码为：" << dreamCode << endl;

    // 对equal进行编码
    string equalCode = codeMap['e'] + codeMap['q'] + codeMap['u'] + codeMap['a'] + codeMap['l'];
    cout << "equal的编码为：" << equalCode << endl;

    // Huffman编码
    string encodedStr = huffmanEncode(str, codeMap);
    cout << "Huffman编码后的字符串为：" << encodedStr << endl;

    return 0;
}