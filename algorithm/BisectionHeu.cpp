#include <BisectionHeu.h>

<<<<<<< Updated upstream
void BisectionHeu::Process(std::vector<int> nums, std::vector<int> freq){
=======
void BisectionHeu::Process(std::vector<int> &nums, std::vector<int> &freq){
    std::vector<int> prefix;
    int n = nums.size();
    prefix.resize(n, 0);
    for (int i = 1; i < n; i ++){
        prefix[i] = prefix[i - 1] + freq[i];
    }
    BuildTree(HBSTroot, 1, n - 1, nums, freq, prefix);
>>>>>>> Stashed changes

}

<<<<<<< Updated upstream
void BuildTree(Node * &root, int l, int r, std::vector<int> nums, std::vector<int> prefix){
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
=======
void BisectionHeu::BuildTree(Node * &root, int l, int r, std::vector<int> &nums, std::vector<int> &freq, std::vector<int> &prefix){
    if (l > r) return;
    int id = l;
    int half = (prefix[r] - prefix[l - 1])/2;
    int le = l, ri = r, mid;
    while (le <= ri){
        mid = (le + ri) / 2;
        if ((prefix[mid] - prefix[l - 1]) < half) le = mid + 1;
        else{
            id = mid;
            ri = mid - 1;
        }
    }
    root = new Node(nums[id], freq[id]);
    BuildTree(root->left, l, id - 1, nums, freq, prefix);
    BuildTree(root->right, id + 1, r, nums, freq, prefix);
>>>>>>> Stashed changes
}