#include <BST.h>

void BuildBST(Node *&root, int l, int r, std::vector<int> rootTable, std::vector<int> freq){
    if (l > r) return;
    int mid = (l + r)/2;
    root = new Node(rootTable[mid], freq[mid]);
    BuildBST(root->left, l, mid - 1, rootTable, freq);
    BuildBST(root->right, mid + 1, r, rootTable, freq);
}

void NLR(Node * root){
    if (!root) return;
    std::cout << root->value << ' ';
    NLR(root->left);
    NLR(root->right);
}