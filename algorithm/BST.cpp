#include <BST.h>

void BuildBST(Node *&root, int l, int r, std::vector<int> rootTable){
    int mid = (l + r)/2;
    root = new Node(rootTable[mid]);
    BuildBST(root->left, l, mid - 1, rootTable);
    BuildBST(root->right, mid + 1, r, rootTable);
}

int SearchNode(Node * root, int key){
    if (!root) return 0;
    if (key == root->value) return 1;
    if (key > root->value) return SearchNode(root->left, key) + 1;
    if (key < root->value) return SearchNode(root->right, key) + 1;

    return 0;
}

void NLR(Node * root){
    if (!root) return;
    std::cout << root->value << ' ';
    NLR(root->left);
    NLR(root->right);
}