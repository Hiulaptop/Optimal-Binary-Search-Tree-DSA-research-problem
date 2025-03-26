#pragma once
#include <AllLibrary.h>

class OptimalBST
{
    public:
    void Process(std::vector<int> nums, std::vector<int> freq);
    void BuildTree(Node * &root, int l, int r, std::vector<int> nums, std::vector<std::vector<int>> rootTable);
    
};
