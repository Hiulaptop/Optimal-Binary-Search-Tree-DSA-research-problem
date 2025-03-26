#include <BisectionHeu.h>

void BisectionHeu::Process(std::vector<int> nums, std::vector<int> freq){
    std::vector<int> prefix;
    int n = nums.size();
    prefix.resize(n, 0);
    for (int i = 1; i < n; i ++){
        prefix[i] = prefix[i - 1] + freq[i];
    }
    BuildTree(BBSTroot, 1, n - 1, nums, prefix);

    // NLR(BBSTroot);
}

void BisectionHeu::BuildTree(Node * &root, int l, int r, std::vector<int> nums, std::vector<int> prefix){
    if (l > r) return;
    int id = l;
    int half = (prefix[r] - prefix[l - 1])/2;
    int le = l, ri = r;
    while (le <= ri){
        id = (le + ri) / 2;
        if ((prefix[id] - prefix[l-1]) < half) le = id + 1;
        else ri = id - 1;
    }
    id = le;
    root = new Node(nums[id]);
    BuildTree(root->left, l, id - 1, nums, prefix);
    BuildTree(root->right, id + 1, r, nums, prefix);
}