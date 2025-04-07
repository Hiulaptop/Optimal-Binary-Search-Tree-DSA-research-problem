#pragma once
#include <AllLibrary.h>

class PerfectBST 
{
    public:
    Node *PBSTroot = nullptr;
    void Process(std::vector<int> &nums, std::vector<int> &freq);
    void BuildBST(Node *&root, int l, int r, std::vector<int> &nums, std::vector<int> &freq);
};