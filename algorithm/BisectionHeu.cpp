#include <BisectionHeu.h>

void BisectionHeu::Process(std::vector<int> nums, std::vector<int> freq){
    std::vector<int> prefix;
    int n = nums.size();
    prefix.resize(n, 0);
    for (int i = 1; i < n; i ++){
        prefix[i] = prefix[i - 1] + nums[i];
    }

    BuildTree(BBSTroot, 1, n - 1, nums, prefix);

    NLR(BBSTroot);
}

void BisectionHeu::BuildTree(Node * &root, int l, int r, std::vector<int> nums, std::vector<int> prefix){
    if (l > r) return;
    int id = l;
    int s1 = prefix[id - 1] - prefix[l - 1];
    int s2 = prefix[r] - prefix[id];
    int mi = INT_MAX;
    while (s2 > s1){
        s1 = prefix[id - 1] - prefix[l - 1];
        s2 = prefix[r] - prefix[id];
        id ++;
    }
    root = new Node(nums[id]);
    BuildTree(root->left, l, id - 1, nums, prefix);
    BuildTree(root->right, id + 1, r, nums, prefix);
}