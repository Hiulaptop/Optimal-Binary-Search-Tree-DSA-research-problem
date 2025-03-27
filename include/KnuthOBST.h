#pragma once
#include <AllLibrary.h>

class KnuthOBST
{
public:
    Node * KBSTroot = nullptr;
    void Process(std::vector<int> nums, std::vector<int> freq);
    void BuildTree(Node * &root, int l, int r, std::vector<int> nums, std::vector<int> freq, std::vector<std::vector<int>> rootTable);
};
