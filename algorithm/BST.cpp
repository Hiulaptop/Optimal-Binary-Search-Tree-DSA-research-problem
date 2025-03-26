#include <BST.h>

void BuildBST(Node *&root, int l, int r, std::vector<int> rootTable){
    int mid = (l + r)/2;
    root = new Node(rootTable[mid]);
    BuildBST(root->left, l, mid - 1, rootTable);
    BuildBST(root->right, mid + 1, r, rootTable);
}



void NLR(Node * root){
    if (!root) return;
    std::cout << root->value << ' ';
    NLR(root->left);
    NLR(root->right);
}