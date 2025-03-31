#include <PerfectBST.h>

void PerfectBST::Process(std::vector<int> &nums, std::vector<int> &freq) {
    PerfectBST::BuildBST(PerfectBST::PBSTroot, 1, nums.size()-1, nums, freq);  
}

void PerfectBST::BuildBST(Node *&root, int l, int r, std::vector<int> &nums, std::vector<int> &freq){
    if (l > r) return;
    int mid = (l + r)/2;
    root = new Node(nums[mid], freq[mid]);
    BuildBST(root->left, l, mid - 1, nums, freq);
    BuildBST(root->right, mid + 1, r, nums, freq);
}

void PerfectBST::NLR(Node * root){
    if (!root) return;
    std::cout << root->value << ' ';
    NLR(root->left);
    NLR(root->right);
}