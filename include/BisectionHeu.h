#pragma once
#include <AllLibrary.h>

class BisectionHeu
{
    public:
<<<<<<< Updated upstream
    Node * BBSTroot = nullptr;
    void Process(std::vector<int> nums, std::vector<int> freq);
    
=======
    Node * HBSTroot = nullptr;
    void Process(std::vector<int> &nums, std::vector<int> &freq);
    void BuildTree(Node * &root, int l, int r, std::vector<int> &nums, std::vector<int> &freq, std::vector<int> &prefix);
>>>>>>> Stashed changes
};